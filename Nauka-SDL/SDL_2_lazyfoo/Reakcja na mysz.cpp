#include <SDL_image.h>
#include <SDL.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>



using namespace std;

const int SCREEN_WIDTH = 1366; //S zerokosc okna
const int SCREEN_HEIGHT = 768; // Wysokosc okna

// Stale przyciskow
const int BUTTON_WIDTH = 911;
const int BUTTON_HEIGHT = 256;
const int TOTAL_BUTTONS = 4;

enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 3

};

// Klasa wrapera
class LTexture
{
	// Aktualna textura sprzetu?
	SDL_Texture* mTexture;

	//  Wymiary obrazu
	int mWidth;
	int mHeight;
public:
	// Inicjalizuje smienne
	LTexture();

	// Dealokuje pamiec
	~LTexture();

	// Laduje obrazek ze sciezki
	bool loadFromFile(string path);

	// Dealokuje texture
	void free();

	// Ustawia modulacje koloru
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	// Ustawia blendowanie?
	void setBlendMode(SDL_BlendMode blending);

	// Ustawia alphe modulacji
	void setAlpha(Uint8 alpha);

	// Renderuje texture w punkcie
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// Pobiera rozmiary obrazka
	int getWidth();
	int getHeight();
};

// Przyciski myszy
class LButton
{
	// Gorny lewy rog
	SDL_Point mPosition;

	// Teraz uzywany sprite globalny
	LButtonSprite mCurrentSprite;
public:

	// Inicjalizacja wewnetrznych zmiennych
	LButton();

	// Ustawia lew gorny rog
	void setPosition(int x, int y);

	// Przchowuje eventy myszy
	void handleEvent(SDL_Event* e);

	// Pokazuje buttony spritow
	void render();
};

// Startuje SDL i tworzy okno
bool init();

// Laduje media
bool loadMedia();

// Uwalnia media, zamyka SDL
void close();

// Okno do ktorego renderujemy
SDL_Window* gWindow = NULL;

// Renderer okna
SDL_Renderer* gRenderer = NULL;

LTexture gBackgroundTexture;// Tlo


// Sprity przyciskow mysz
SDL_Rect gSpriteClips[BUTTON_SPRITE_TOTAL];
LTexture gButtonSpriteSheetTexture;

// Objekty przyciskow
LButton gButtons[TOTAL_BUTTONS];

LTexture::LTexture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	free();
}

bool LTexture::loadFromFile(string path)
{
	// Wyrzucenie przedistniejacej textury
	free();

	// Finalna textura
	SDL_Texture* newTexture = NULL;

	// £adowanie obrazka ze œcierzki
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
		cout << "Nie mozna zaladowac obrazka z " << path.c_str() << "SDL_image Error" << IMG_GetError() << endl;
	else
	{
		// Klucz koloru obrazka
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0, 0));

		// Tworzenie textury z pixei powierzchni?
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
			cout << "Nie mozna zrobic textury z obrazka " << path.c_str() << "SDL_image Error" << IMG_GetError() << endl;
		else
		{
			// Pobranie wymiarow obrazka
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		// Wywalenie starej zaladowanej textury
		SDL_FreeSurface(loadedSurface);
	}

	// Return sukcesu
	mTexture = newTexture;
	return mTexture != NULL;
}


void LTexture::free()
{
	// Zwolnij texture jesli jakas istenieje
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	// Modulacja rgb textury 
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void LTexture::setBlendMode(SDL_BlendMode blending)
{
	// Ustawia funkcje blendowania
	SDL_SetTextureBlendMode(mTexture, blending);
}

void LTexture::setAlpha(Uint8 alpha)
{
	// Modulacja alpha textury
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center ,SDL_RendererFlip flip)
{
	// Ustawia renderowana przstrzen i irenderuje na ekran
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	// Ustawia wymiary clipu?
	if(clip!=NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	// Renderuje na ekran
	SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int LTexture::getHeight()
{
	return mHeight;
}

int LTexture::getWidth()
{
	return mWidth;
}

LButton::LButton()
{
	mPosition.x = 0;
	mPosition.y = 0;

	mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void LButton::setPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}

void LButton::handleEvent(SDL_Event* e)
{
	// Jesli zajdzie zdarzenie myszy
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		// Poberz pozycje myszy
		int x, y;
		SDL_GetMouseState(&x, &y);

		// Sprawdz czy mysz jest na przycisku
		bool inside = true;

		// Mysz jest z lewo?
		if (x < mPosition.x)
			inside = false;

		// Mysz z prawej?
		else if (x>mPosition.x + BUTTON_WIDTH)
			inside = false;

		// Mysz nad przyciskiem
		else if (y < mPosition.y)
			inside = false;
		
		// Mysz pod przyciskiem
		else if (y > mPosition.y + BUTTON_HEIGHT)
			inside = false;
		
		//Mysz poza przyciskiem
		if (!inside)
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		else
		{
			// Ustawia sprite myszy
			switch(e->type)
			{
			case SDL_MOUSEMOTION:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;

			case SDL_MOUSEBUTTONDOWN:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				break;

			case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;
			}
		}
	}
}


void LButton::render()
{
	// Pokazuje obecny sprite dla przycisku
	gButtonSpriteSheetTexture.render(mPosition.x, mPosition.y, &gSpriteClips[mCurrentSprite]);
}

bool init()
{
	// Flaga sukcesu
	bool success = true;

	// Inicjalizacja SDL
	if (SDL_Init(SDL_INIT_VIDEO)<0)
	{
		cout << "SDL nie zainicjalizowany, SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
			cout << "Uwaga: Liniowe filtrowanie textur niemozliwe" << endl;


		// Tworzenie okna
		gWindow = SDL_CreateWindow("Przezroczystosc spritow", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "Okno nie moze zostac stworzone, SDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				cout << "Renderer nie moze zostac stworzony, SDL Error " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				//SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Inicjalizacja obrazka PNG
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags)&imgFlags))
				{
					cout << "SDL_image nie moze byc zainicjalizowany, SDL_Error: " << SDL_GetError() << endl;
					success = false;
				}
			}
		}

	}
	return success;
}


bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprites
	if (!gButtonSpriteSheetTexture.loadFromFile("c:/Users/tomek/OneDrive/Documents/Studia/Semestr II/PO projekt/Grafiki/Splashe/prod-all.png"))
	{
		printf("Failed to load button sprite texture!\n");
		success = false;
	}
	else
	{
		//Set sprites
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClips[i].x = 0;
			gSpriteClips[i].y = i * 256;
			gSpriteClips[i].w = BUTTON_WIDTH;
			gSpriteClips[i].h = BUTTON_HEIGHT;
		}

		//Set buttons in corners
		gButtons[0].setPosition(SCREEN_WIDTH-911, SCREEN_HEIGHT/3);
	//	gButtons[1].setPosition(SCREEN_WIDTH - BUTTON_WIDTH, 0);
	//	gButtons[2].setPosition(0, SCREEN_HEIGHT/3 - BUTTON_HEIGHT);
	//	gButtons[3].setPosition(SCREEN_WIDTH - BUTTON_WIDTH, SCREEN_HEIGHT - BUTTON_HEIGHT);
	}
	// Ladowanie tla
	if (!gBackgroundTexture.loadFromFile("s:/SDL Tutorial/spriteAdriana01/rozgrywka.png"))
	{
		cout << "Nie zaladowano Tla" << endl;
		success = false;
	}
	return success;
}

void close()
{
	//Free loaded images
	gButtonSpriteSheetTexture.free();

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}

					//Handle button events
					//for (int i = 0; i < TOTAL_BUTTONS; ++i)
					//{
						gButtons[0].handleEvent(&e);
				//	}
				}

				//Clear screen
				//SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				gBackgroundTexture.render(0, 0);
				//Render buttons
				//for (int i = 0; i < TOTAL_BUTTONS; ++i)
				//{
					gButtons[0].render();
				//}

				//Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	//Free resources and close SDL
	close();
	_getch();

	return 0;
}
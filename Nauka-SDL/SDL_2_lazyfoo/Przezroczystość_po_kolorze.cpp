#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 1366; //S zerokosc okna
const int SCREEN_HEIGHT = 798; // Wysokosc okna


// Klasa wrappera textur
class LTexture
{
	// Aktualna textura hardwareowa
	SDL_Texture* mTexture;

	// Wymiary obrazka
	int mWidth;
	int mHeight;

public:

	LTexture();
	~LTexture();

	// £aduje obrazek ze œcierzki
	bool loadFromFile(string path);

	// Dealokacja textury
	void free();

	// Renderuje texture we wkazanym punckie
	void render(int x, int y);

	// Pobiera wymiary obrazu
	int getWidth();
	int getHeight();

};

// Okno do ktorego renderujemy
SDL_Window* gWindow = NULL;

// Renderer okna
SDL_Renderer* gRenderer = NULL;

// Textury Sceny
LTexture gFooTexture;		// Sprite
LTexture gBackgroundTexture;// Tlo

LTexture::LTexture()
{
	//Inicjalizacja
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	// Dealokacja
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
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));
		
		// Tworzenie textury z pixei powierzchni?
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture==NULL)
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

void LTexture::render(int x, int y)
{
	// Ustawienie obszaru i renderu na ekran
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad);
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

bool init()
{
	// Flaga sukcesu
	bool success = true;

	// Inicjalizacja SDL
	if(SDL_Init(SDL_INIT_VIDEO)<0)
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
		if(gRenderer==NULL)
		{
			cout << "Renderer nie moze zostac stworzony, SDL Error " << SDL_GetError() << endl;
			success = false;
		}
		else
		{
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

			// Inicjalizacja obrazka PNG
			int imgFlags = IMG_INIT_PNG;
			if(!(IMG_Init(imgFlags)&imgFlags))
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
	// Flaga sukcesu
	bool success = true;

	// Ladowanie textury sprita
	if (!gFooTexture.loadFromFile("s:/SDL Tutorial/spriteAdriana01/arzt.png"))
	{
		cout << "Nie zaladowano Textury sprita" << endl;
		success = false;
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
	// Uwalnia media
	gFooTexture.free();
	gBackgroundTexture.free();

	// Niszczy okno
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	// Wychodzi z podsystemu SDL
	IMG_Quit();
	SDL_Quit();
}

int main( int argc, char* args[])
{
	// Startuje SDL i tworzy okno
	if (!init())
		cout << "Nie zainicjalizowano" << endl;
	else
	{
		// Laduje media
		if (!loadMedia())
			cout << "Nie zaladowano miedow" << endl;
		else
		{
			// Flaga glownej petli
			bool quit = false;

			// Trzymacz eventow
			SDL_Event e;

			// Poki appka dziala
			while(!quit)
			{
				// Trzymacz evenuw kolejce
				while (SDL_PollEvent(&e) != 0)
				{
					// Uzytkownik chce wyjsc
					if (e.type == SDL_QUIT)
						quit = true;
				
			}

			// Czyszczenie ekranu
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(gRenderer);

			// Renderuje tlo
			gBackgroundTexture.render(0, 0);

			// Renderuje sprita
			gFooTexture.render(521, 130);

			// Update okna
			SDL_RenderPresent(gRenderer);
		}
	}
}
close();
return 0;
}
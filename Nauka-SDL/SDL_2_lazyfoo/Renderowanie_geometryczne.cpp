#include  <SDL.h>
#include <SDL_image.h>
#include <conio.h>
#include <math.h>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;

bool init();
bool loadMedia();
void close();
SDL_Texture* loadTexture(string path);
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

bool init()
{
	bool success = true;

	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		cout << "SDl nie zostal zainicjalizowany\nSDL_Error: " << SDL_GetError();
		success = false;
	}
	else
	{
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1"))
		{
			cout << "Uwaga: Liniowe filtrowanie tekstur niedostepne" << endl;
		}

		gWindow = SDL_CreateWindow("renderowanie geometryczne", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow==NULL)
		{
			cout << "Okno nie zostalo uworzeone\nSDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				cout << "Renderer nie moze zostac stworzoney\nSDL_Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				// Inicjalizacja kolorow renderera
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Inicjalizacja ladowania PNG
				int imgFlags = IMG_INIT_PNG;
				if(!(IMG_Init(imgFlags)&imgFlags))
				{
					cout << "SDL_image nie moze byc ainicjalizowane\nSDL_Error: " << IMG_GetError() << endl;
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

	// Nic do zaladowania
	return success;
}

void close()
{
	// Niszczenie okna
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	// Niszczenie renderera
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;

	// WYchodenie z sdl
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture(string path)
{
	// Finalna textura
	SDL_Texture* newTexture = NULL;

	// Ladowanie obrazka ze sciezki
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface==NULL)
	{
		cout << "Nie mozna zaladowac obrazka\nIMG_Error" << IMG_GetError() << endl;
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
			cout << "Nie mozna stworzyc tekstury z obrazka ze sciezki\nSDL_Error: " << SDL_GetError() << endl;

		// Uwolnienie starej powierzchni
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}

int main(int argc, char* args[])
{
	if (!init())
		cout << "Nie zainicjaliowao" << endl;
	else
	{
		if (!loadMedia())
			cout << "Nie zaladowano miediow" << endl;
		else
		{
			// Flaga glownej petli
			bool quit = false;

			// Event handler
			SDL_Event e;

			while(!quit)
			{
				// Kolejkuje eventy
				while(SDL_PollEvent(&e)!=0)
				{
					// Uzytkownik chce wyjsc
					if (e.type == SDL_QUIT)
						quit = true;
				}
			
				// Wyczyszczenie ekranu
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				// Czerwone wpelnienie 
				SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
				SDL_RenderFillRect(gRenderer, &fillRect);

				// Zielony kontur
				SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
				SDL_RenderDrawRect(gRenderer, &outlineRect);

				// Niebieska linia pozioma
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);
				SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);
			
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0x00, 0xFF);
				for (int i = 0; i < SCREEN_HEIGHT; i += 4)
					SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);

				//Update ekranu
				SDL_RenderPresent(gRenderer);
			}
		}
	}
	close();
	return 0;
}
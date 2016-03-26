#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 1366; //S zerokosc okna
const int SCREEN_HEIGHT = 798; // Wysokosc okna

// Laduje obrazek jako teksture
SDL_Texture* loadTexture(string path);

// Okno do ktorego renderujemy
SDL_Window* gWindow = NULL;

// Renderer okna
SDL_Renderer* gRenderer = NULL;

// Wyswietlana wlasnie tekstura
SDL_Texture* gTexture = NULL;

bool init();
bool loadMedia();
void close();

bool init()
{
	// Inicjalizacja flagi
	bool success = true;

	// Inicjalizacja SDL
	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		cout << "Nie udalo sie zainicjowac SDL\nSDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		// Ustawienie filtrowania textur na liniowe
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
			cout << "UWAGA: Liniowe filtrowanie textur nieaktywne" << endl;
		
		// Tworzenie okna
		gWindow = SDL_CreateWindow("Renderowanie", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(gWindow==NULL)
		{
			cout << "Okno nie mog³o zostac stworzone\nSDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{
			// Tworzenie renderera dla okna
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if(gRenderer==NULL)
			{
				cout << "Renderer nie mogl zostac stworzony\nSDL_Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				// Inicjalizacja koloru renderera
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Inicjalizacja ladowania PNG
				int imgFlags = IMG_INIT_PNG;
				if(!(IMG_Init(imgFlags)&imgFlags))
				{
					cout << "SDL_image nie moze inicjalizowac\nSDL_image Error: " << IMG_GetError() << endl;
					success = false;
				}
			}
		}
	}
	return success;
}

SDL_Texture* loadTexture(string path)
{
	// Ostatecza tekstura
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
		cout << "Nie mozna zaladowac obrazka\nIMG_Error: " << IMG_GetError() << endl;
	else
	{
		// Tworzenie textury z pixeli powierzchni
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
			cout << "Nie mozna utworzyc tekstury z " << path.c_str() << endl << "SDL_Error" << SDL_GetError() << endl;

		// Uwolanienie ladowanej powierzchni
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}

bool loadMedia()
{
	// Ladowanie flagi sukcesu
	bool success = true;

	// Ladowanie textury PNG
	gTexture = loadTexture("S:/SDL Tutorial/koncept2.png");
	if(gTexture==NULL)
	{
		cout << "Nie zaladowano obrazka textury" << endl;
		success = false;
	}
	return success;
}

void close()
{
	// Uwolnienie zaladowanego obrazka
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	// Niszczenie okien
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gRenderer = NULL;
	gWindow = NULL;

	// Wyjscie z subsystemu SDL
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	// Start SDL i stworzenie okna
	if (!init())
		cout << "Nie zainicjalizowano" << endl;
	else
	{
		// Ladowanie miediow
		if (!loadMedia())
			cout << "Nie zaladowano mediow" << endl;
		else
		{
			// Flaga wyjscia
			bool quit = false;

			// Zmienna przechowuje event
			SDL_Event e;

			// Petla gry
			while (!quit)
			{
				// Petla eventu
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				// Czyszczenie ekranu
				SDL_RenderClear(gRenderer);

				// Renderowanie textury na ekran
				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

				// Update ekranu
				SDL_RenderPresent(gRenderer);
			}

		}


	}

	// Zwolnienie  SDL
	close();

	
	_getch();
	return 0;
}
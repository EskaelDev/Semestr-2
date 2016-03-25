
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 1366; //S zerokosc okna
const int SCREEN_HEIGHT = 798; // Wysokosc okna

							   //Protorypy
bool init();	// inicjalizacja SDL
bool loadmedia();	// inicjalizacja mediow
void close();	// Zwalnia media, zamyka SDL


SDL_Surface* loadSurface(string path); // Ladowanie powierzchni
SDL_Window* gWindow = NULL; // Okno
SDL_Surface* gScreeenSurface = NULL; // Powierzchnia w oknie
SDL_Surface* gPNGSurface = NULL; // Obrazek PNG


bool init()
{
	// Inicjalizacja flagi sukcesu
	bool success = true;

	// Inicjalizacja SDL
	if (SDL_Init(SDL_INIT_VIDEO)<0)		// Jak cos spieprzone daje -1
	{
		cout << "SDL nie zostal zainicjalizowany" << endl <<
			"SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}

	else
	{				//Tworzenie okna: Tytul, pozycja x, pozycja y, szerokosc okna, wysokosc okna, okno ma byc wyswietlone lub ukryte
		gWindow = SDL_CreateWindow("Obrazek PNG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "Okno nie zostalo utworzone" << endl <<
				"SDL_Error: " << SDL_GetError << endl;
			success = false;
		}
		else
		{
			// Inicjalizacja ladowania PNG
			int imgFlags = IMG_INIT_PNG;
			if(!(IMG_Init(imgFlags) & imgFlags))
			{
			cout << "SDL_image nie zosta³o zainicjalizowane" << endl <<
				"SDL_Error: " << SDL_GetError << endl;
			success = false;
			}
			else
			gScreeenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}


bool loadmedia()
{
	// Zaladowanie flagi sukcesu
	bool success = true;

	// £adowanie obrazka domyslnego
	gPNGSurface = loadSurface("S:/SDL Tutorial/koncept2.png");
	if (gPNGSurface == NULL)
	{
		cout << "Nie zaladowano obrazka domyslnego" << endl <<
			"SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}

	return success;
}

void close()
{
	// Uwolnienie powierzchni strechowanej SDL
	SDL_FreeSurface(gPNGSurface);
	gPNGSurface = NULL;

	// Niszczenie okna
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Wyjœcie z subsystemu SDL
	IMG_Quit();
	SDL_Quit();
}

// Ladowanie zdjecia z okreslona sciezka
SDL_Surface* loadSurface(string path)
{
	// Zoptymalizowany obrazek
	SDL_Surface* optimizedSurface = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
		cout << "Nie udalo sie zaladowac zdjecia" << endl <<
		"SDL_Error: " << SDL_GetError() << endl;
	else
	{
		// Konwertowanie powierzchni do formatu ekranu
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreeenSurface->format, NULL);
		if (optimizedSurface == NULL)
			cout << "Nie udalo sie zaladowac zoptymalizowaego zdjecia" << endl <<
			"SDL_Error: " << SDL_GetError() << endl;

		// Uwolnienie orginalnego obrazka
		SDL_FreeSurface(loadedSurface);

	}
	return optimizedSurface;
}


int main(int argc, char* args[])
{
	// Start SDL i stworzenie okna
	if (!init())
		cout << "Nie zainicjalizowano" << endl;
	else
	{
		// Ladowanie miediow
		if (!loadmedia())
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


				// Zaaplikowanie zdjecia strechowanego
				SDL_BlitScaled(gPNGSurface, NULL, gScreeenSurface, NULL);

				// Update powierzchni
				SDL_UpdateWindowSurface(gWindow);
			}

		}


	}

	// Zwolnienie  SDL
	close();

	
	return 0;
}
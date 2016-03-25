//Using SDL and standard IO
#include <SDL.h>
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
SDL_Surface* gStrechedSurface = NULL; // Obrazek wyswitlany


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
		gWindow = SDL_CreateWindow("Pierwsze okno", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "Okno nie zostalo utworzone" << endl <<
				"SDL_Error: " << SDL_GetError << endl;
			success = false;
		}
		else
		{
			// surface staje powierzchnia dla tego okna
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
	gStrechedSurface = loadSurface("S:/SDL Tutorial/05_optimized_surface_loading_and_soft_stretching/stretch.bmp");
	if (gStrechedSurface == NULL)
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
	SDL_FreeSurface(gStrechedSurface);
	gStrechedSurface = NULL;

	// Niszczenie okna
	SDL_DestroyWindow(gWindow);

	//Wyjœcie z subsystemu SDL
	SDL_Quit();
}

// Ladowanie zdjecia z okreslona sciezka
SDL_Surface* loadSurface(string path)
{
	// Zoptymalizowany obrazek
	SDL_Surface* optimizedSurface = NULL;

	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
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
				SDL_BlitScaled(gStrechedSurface, NULL, gScreeenSurface, NULL);

				// Update powierzchni
				SDL_UpdateWindowSurface(gWindow);
			}

		}


	}

	// Zwolnienie  SDL
	close();

	_getch();
	return 0;
}
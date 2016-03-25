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

// Wyliczenie klawiszy
enum KeyPressesSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL,
};

SDL_Surface* loadSurface(string path); // Ladowanie powierzchni
SDL_Window* gWindow = NULL; // Okno
SDL_Surface* gScreeenSurface = NULL; // Powierzchnia w oknie
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL]; // Obrazki przypisane do klawiszy
SDL_Surface* gCurrentSurface = NULL;// Obrazek

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
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("S:/SDL Tutorial/koncept2.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
	{
		cout << "Nie zaladowano obrazka domyslnego" << endl <<
			"SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}

	// £adowanie obrazka górnego
	gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("S:/SDL Tutorial/pierwsze.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
	{
		cout << "Nie zaladowano obrazka górnego" << endl <<
			"SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}

	// £adowanie obrazka dolnego
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("S:/SDL Tutorial/drugie.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
	{
		cout << "Nie zaladowano obrazka dolnego" << endl <<
			"SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}

	// £adowanie obrazka lewego
	gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("S:/SDL Tutorial/trzecie.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
	{
		cout << "Nie zaladowano obrazka lewego" << endl <<
			"SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}

	// £adowanie obrazka prawego
	gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("S:/SDL Tutorial/drugie.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
	{
		cout << "Nie zaladowano obrazka prawego" << endl <<
			"SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}


	return success;
}

void close()
{
	// Uwolnienie powierzchni SDL
	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i)
	{
		SDL_FreeSurface(gKeyPressSurfaces[i]);
		gKeyPressSurfaces[i] = NULL;
	}

	// Niszczenie okna
	SDL_DestroyWindow(gWindow);

	//Wyjœcie z subsystemu SDL
	SDL_Quit();
}

// Ladowanie zdjecia z okreslona sciezka
SDL_Surface* loadSurface(string path)
{
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL)
		cout << "Nie udalo sie zaladowac zdjecia" << endl <<
		"SDL_Error: " << SDL_GetError() << endl;

	return loadedSurface;
}


int main(int argc, char* args[] )
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

			// Domyslna powierzchnia
			gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

			// Petla gry
			while(!quit)
			{
				// Petla eventu
				while(SDL_PollEvent(&e) !=0)
				{
					if (e.type == SDL_QUIT )
					{
						quit = true;
					}

					// Nacisniecie klawisza
					else 
						if (e.type == SDL_KEYDOWN)
						{
							// Wybranie powierzchni na podstawie klawisza
							switch (e.key.keysym.sym)
							{
							case SDLK_UP:
								gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
								break;

							case SDLK_DOWN:
								gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
								break;

							case SDLK_LEFT:
								gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
								break;

							case SDLK_RIGHT:
								gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
								break;

							default:
								gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
								break;
							}

						}

				}


				// Zaaplikowanie zdjecia
				SDL_BlitScaled(gCurrentSurface, NULL, gScreeenSurface, NULL);

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
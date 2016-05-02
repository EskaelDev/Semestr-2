#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;


const int SCREEN_WIDTH = 456; // Szerokosc okna
const int SCREEN_HEIGHT = 768; // Wysokosc okna


// Klasa wrappera
class LTexture
{
	// Aktalna textura sprz�tu
	SDL_Texture* mTexture;

	// Wymiary obrazka
	int mWidth, mHeight;

public:
	// Kostruktor domyslny
	LTexture();

	// Dekonstruktor zwalnia pami��
	~LTexture();
	
	// �aduje obrazek ze �cie�ki
	bool loadFromFile(string path);

	// Tworzy obrazek z sciezki do czcionki
	bool loadFromRenderedText(string textureText, SDL_Color textColor);

	// Dealokacja textury
	void free();

	// Ustawia modulacje kolor�w
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	// Sutawia blendowanie
	void SetBlendMode(SDL_BlendMode blending);

	// Ustawie modulacje kanalu alfa
	void setAlpha(Uint8 alpha);

	// Renderuje texture na podaym punkcje
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// returnuje rozmiary
	int getWidth();
	int getHeight();
};

/*	 Prototypy i zmienne globalne	*/		

// Startuje SDL i tworzy okno
bool init();

// �aduje media
bool loadMedia();

// Zwalnia media, zamyka SDL
void close();

// Okno w kt�rym b�dzie renderowanie
SDL_Window* gWindow = NULL;

// Renderer okna
SDL_Renderer* gRenderer = NULL;

// U�ywana czcionka
TTF_Font *gFont = NULL;

// Renderowana textura
LTexture gTextTexture;

/*			METODY LTEXTURE			*/

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
	// Usuwa texture kt�ra jest a jej nie ma
	free();

	// Ostateczna textura
	SDL_Texture* newTexture = NULL;

	// �aduje obrazek ze �cie�ki
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
		cout << "Nie mozna otworzyc obrazka z : " << path.c_str() << " SDL_image Error: "<< IMG_GetError()<<endl;
	else
	{
		// Klucz korowu obrazka??
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		// Tworzy txture z pixeli powierzchni??
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
			cout << "Nie mozna stworzyc textury z " << path.c_str() << " SDL Error: " << SDL_GetError() << endl;
		else
		{
			// Wpisuje rozmiary 
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		// Pozbywa si� starej powierzchni
		SDL_FreeSurface(loadedSurface);
	}
	// Returnuje sukces
	mTexture = newTexture;
	return mTexture != NULL;
}

bool LTexture::loadFromRenderedText(string textureText, SDL_Color textColor)
{
	// Pozbywa si� przedegzystuj�cej textury...
	free();

	// Renderuje powierzchnie dla tekstu
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface == NULL)
		cout << "Nie mozna wyrenderowac powirzchni textu! SDL_ttf Error: " << TTF_GetError() << endl;
	else
	{
		mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (mTexture == NULL)
			cout << "Nie mzna stworzyc extury z renderowanego tekstu! SDL Error: " << SDL_GetError() << endl;
		else
		{
			// Pobiera wymiary obrazka
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		// Pozbywa si� starej powierzchni
		SDL_FreeSurface(textSurface);
	}

	// Returnuje sukces
	return mTexture != NULL;
}





// Sortowanie_Struct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <malloc.h>
FILE *plik;


enum Wybor
{
	SR_ROS,
	SR_MAL,
	MAX_ROS,
	MIN_MAL
};

struct point
{
	float *tab;
	int rozmiar;
};

float* WczytajDane(const char *NazwaPliku, int *n)
{
	if ((plik = fopen(NazwaPliku, "r")) == NULL)
	{
		printf("Blad otwarcia pliku %s", NazwaPliku);
		return false;
	}

	fscanf(plik, "%d", n);
	float *tab = (float*)malloc(sizeof(float)*(*n));

	for (int i = 0; i < (*n); i++)
		fscanf(plik, "%f", &tab[i]);

	return tab;

}

void SortujPrzezWybieranie(float *Dane, const int rozmiar, Wybor)
{
	int k;
	float x;

	for (int i = 0; i < rozmiar; i++)
	{
		k = i;
		for (int j = i + 1; j < rozmiar; j++)
		{
			if (Dane[j] < Dane[k])
				k = j;
		}

		x = Dane[k];
		Dane[k] = Dane[i];
		Dane[i] = x;
	}
}

int main()
{
    return 0;
}


// Sortowanie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <malloc.h>
#include <conio.h>

FILE *plik;

bool Test(const float * const tab, const int n)
{
	if (tab == 0)
		return false;
	if (n <= 0)
		return false;
	if (n > 100000)
		return false;
	for (int i = 0; i < n - 1; ++i)
	{
		if (tab[i] > tab[i + 1])
			return false;
	}
	return true;	
}

float* WczytajDane(const char *NazwaPliku, int *n)
{
	if((plik=fopen(NazwaPliku, "r"))==NULL)
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

void SortujBabelkowo(float *Dane, const int n)
{
	int i, j;
	float x;

	for (i=0; i < n-1; i++)
	{
		for (j=0; j < n-1; j++)
		{
			if(Dane[j]>Dane[j+1])
			{
				x = Dane[j+1];
				Dane[j+1] = Dane[j];
				Dane[j] = x;
			}
		}
	}
}

void SortujPrzezWybieranie(float *Dane, const int n)
{
	int k;
	float x;

	for (int i = 0; i < n; i++)
	{
		k = i;
		for (int j = i + 1; j < n; j++)
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
	int n;

	float *tab = WczytajDane("liczby.txt", &n);
	printf("Liczba danych: %d\n", n);

	SortujBabelkowo(tab, n);
	printf("Metoda sortowania Babelkowego.\n");
	if (Test(tab, n))
		printf("Dane posortowane prawidlowo.\n");
	else printf("Dane posortowane nieprawidlowo.\n");

	SortujPrzezWybieranie(tab, n);
	printf("Metoda sortowanie przez wybieranie.\n");
	if (Test(tab, n))
		printf("Dane posortowane prawidlowo.\n");
	else printf("Dane posortowane nieprawidlowo.\n");

	free(tab);
	_getch();

    return 0;
}


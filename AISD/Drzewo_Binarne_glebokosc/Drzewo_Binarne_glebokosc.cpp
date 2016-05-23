// Drzewo_Binarne_glebokosc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <corecrt_malloc.h>
#include <conio.h>
#include <cstring>

struct d¿ewo
{
	double dane; 
	char *slowo;
	struct d¿ewo *lewy, *prawy;
};

struct d¿ewo *Nowe_d¿ewo(double _dane, char* slowo_str)
{
	struct d¿ewo * nowe = (struct d¿ewo*)malloc(sizeof(struct d¿ewo));
	nowe->dane = _dane;
	nowe->slowo = NULL;
	nowe->slowo = (char*)malloc(10 * sizeof(char));
	strcat(nowe->slowo, slowo_str);
	nowe->lewy = nowe->prawy = 0;
	return nowe;
}

void Wstaw_d¿(struct d¿ewo *rut, double _dane, char* slowo_str)
{
	for(;;)
	{
		if (_dane<rut->dane)
		{
			if (rut->lewy == 0)
			{
				rut->lewy = Nowe_d¿ewo(_dane, slowo_str);
				return;
			}
			else
				rut = rut->lewy;
			}
		else{
			if(rut->prawy==0)
			{
				rut->prawy = Nowe_d¿ewo(_dane, slowo_str);
				return;
			}
			else rut = rut->prawy;
		}
	}
}

int l = 0, p = 0;

void Wyswietl(struct d¿ewo * rut)
{
	printf("%.2lf | %s\n", rut->dane, rut->slowo);
	if (rut->lewy != NULL)
	{
		++l;
		printf("l: %d/", l);
		Wyswietl(rut->lewy);
	}
	if (rut->prawy != NULL)
	{
		++p;
		printf("p: %d\\", p);
		Wyswietl(rut->prawy);
	}
}

bool Wyszukaj(d¿ewo* rut, float _dane)
{
	if (rut == NULL)
		return false;
	else if (rut->dane == _dane)
		return true;
	else if (rut->dane < _dane)
		return Wyszukaj(rut->prawy, _dane);
	else return Wyszukaj(rut->lewy, _dane);
}

void Zwalnianie(d¿ewo *rut)
{
	if (rut->lewy != NULL)
		Zwalnianie(rut->lewy);
	if (rut->prawy != NULL)
		Zwalnianie(rut->prawy);
	delete rut;
}


int main()
{
	double do_szukania = 9.99;
	double Ÿ;
	char *œ;
	FILE *no_plik;
	if ((no_plik = fopen("plik.txt", "r")) != NULL) {
	//	printf("Plik jest\n");
		fscanf(no_plik, "%lf", &Ÿ);
		œ = (char*)malloc(sizeof(char)*(10));
		fscanf(no_plik, "%lf", &œ);

		d¿ewo *ent = Nowe_d¿ewo(Ÿ, œ);
		free(œ);
	//	printf("ent jest\n");

		while (!feof(no_plik))
		{
			fscanf(no_plik, "%lf", &Ÿ);

			œ = (char*)malloc(sizeof(char)*(10));
			fscanf(no_plik, "%s", &œ);
			//printf("Ÿ=%lf\n", Ÿ);
			Wstaw_d¿(ent, Ÿ, œ);
			free(œ);

		}

		printf("Leci drzewo!\n");
		Wyswietl(ent);

		printf("\n%d", Wyszukaj(ent, 9.99));
		printf("\n%d", Wyszukaj(ent, 2.50000000));
		Zwalnianie(ent);
	}
	else
		printf("Chuju pliku nie ma\n");
	getch();
    return 0;
}


// Kolejka.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>

struct Kolejka
{
	double *data;
	int capacity;
	int size;
};

Kolejka* StworzKolejke(const unsigned int Rozmiar)
{
	if (Rozmiar>0)
	{
		Kolejka *k = new Kolejka;
		k->capacity = Rozmiar;
		k->size = 0;
		k->data = new double[Rozmiar];
		return k;
	}

	return 0;
}

void ZniszczKolejke(Kolejka *K)
{
	delete[]K->data;
}


unsigned int Rozmiar(Kolejka *K)
{
	return K->capacity;
}

unsigned int Elementy(Kolejka *K)
{
	return K->size;
}

void Wstaw(Kolejka *K, const double V)
{
	if(K->size<K->capacity)
	{
		K->data[K->size++] = V;
	}
}

double Wyjmij(Kolejka *K)
{
	if(K->size>0)
	{
		return K->data[--K->size];
	}
	return 0;
}

int main()
{
	Kolejka *K = StworzKolejke(10);
	for (double V = 10.0; V < 20.0; V += 1.0)
	{
		printf("Wstawiam %.1f - ", V);
		Wstaw(K, V);
		printf("%d z %d elemenetow.\n", Elementy(K), Rozmiar(K));
	}
	for (unsigned int i = 0; i <= 10; i++)
	{
		printf("%d - wyjalem %.1f\n", i, Wyjmij(K));
	}
	ZniszczKolejke(K);
	_getch();
    return 0;
}


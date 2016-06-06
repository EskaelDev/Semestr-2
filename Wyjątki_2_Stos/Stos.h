#pragma once
#include "StosPusty.h"
#include "BrakMiejsc.h"
#include "NiepoprawnaAlokacja.h"

class Stos
{
	int pojemnosc, *tab, rozmiar;
public:
	Stos(int pojemnosc )
	{
		rozmiar = 0;	
		if (pojemnosc < 10 || pojemnosc>1000)
		{
			throw NiepoprawnaAlokacja();
		}
		else
		{
			this->pojemnosc = pojemnosc;
			tab = new int[this->pojemnosc];
		}
	}
	void Odloz(int wartosc)
	{
		if (rozmiar == pojemnosc)
			throw BrakMiejsc();
		else
		{
			tab[rozmiar] = wartosc;
			rozmiar++;
		}
	}
	int Pobierz()
	{
		if (rozmiar < 1)
			throw StosPusty();
		else
		{
			int wartosc = tab[rozmiar];
			rozmiar--;
			return wartosc;
		}	
	}

	int Minimum()
	{
		if (rozmiar < 1)
			throw StosPusty();
		else
		{
			int minimum = 0;
			for (int i = 0; i < rozmiar; i++)
			{
				if (minimum > tab[i])
					minimum = tab[i];
			}
			return minimum;
		}	
	}
	void WyswietlStos()
	{
		if (rozmiar == 0)
			throw StosPusty();
		for (int i = 0; i < rozmiar; i++)
		{
			std::cout << tab[i] << std::endl;
		}
	}
	~Stos()
	{
		delete[] tab;
	}
};


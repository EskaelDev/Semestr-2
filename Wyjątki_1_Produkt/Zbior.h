#pragma once
#include "Produkt.h"

class Zbior
{
	int rozmiar, pojemnosc;
	Produkt * tab[20];
public:
	Zbior()
	{
		rozmiar = 0;
		pojemnosc = 20;
		for (int i = 0; i < pojemnosc; i++)
		{
			tab[i] = NULL;
		}
	}
	void DodajProdukt(Produkt *produkt)
	{
		rozmiar++;
		tab[rozmiar-1] = new Produkt(produkt->GetNazwa(), produkt->GetCena());
	}
	int GetLiczbaProduktow()
	{
		return rozmiar;
		
	}
	Produkt* GetProdukt(int ktory)
	{
		return tab[ktory];
	}
	float GetSuma()
	{
		float wynik=0;
		for(int i = 0 ; i<rozmiar;i++)
		{
			wynik += tab[i]->GetCena();
		}
		return wynik;
	}

	~Zbior();
};


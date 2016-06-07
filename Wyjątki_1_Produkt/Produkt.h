#pragma once
#include <iostream>
#include <string>

using namespace std;

class Produkt
{
	string nazwa;
	float cena;
public:
	Produkt(string nazwa, float cena)
	{
		this->nazwa = nazwa;
		this->cena = cena;
	}

	string GetNazwa()
	{
		return nazwa;
	}
	float GetCena()
	{
		return cena;
	}
};


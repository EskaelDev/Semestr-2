#pragma once
#include "Nosnik.h"
class Macierz :
	public Nosnik
{
	string opis;
public:
	Macierz(string opis)
	{
		if(opis=="Macierz")
		this->opis = opis;
	}

	~Macierz();
};


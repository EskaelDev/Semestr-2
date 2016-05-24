#pragma once
#include "Figura.h"


class Kolo :
	public Figura
{
	int r;
public:
	Kolo(string opis, int r)
	{
		this->r = r;
	}
	string Nazwa()
	{
		return "Kolo";
	}
	int PolePowierzchni()
	{
		return PI*pow(r, 2);
	}
	double Obwod()
	{
		return PI*2*r;
	}
};


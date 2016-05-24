#pragma once
#include "Figura.h"

const int PI = 3.14;

class Elipsa :
	public Figura
{
	int a, b;
public:
	Elipsa(string opis, int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	string Nazwa()
	{
		return "Elipsa";
	}
	int PolePowierzchni()
	{
		return PI*a*b;
	}
	double Obwod()
	{
		if (a>b)
		return PI*((3 / 2)*(a + b) - sqrt(a - b));
		else
			return PI*((3 / 2)*(a + b) - sqrt(b - a));

	}
};


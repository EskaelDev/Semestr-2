#pragma once
#include "Figura.h"
class Prostokat :
	public Figura
{
	int a, b;
public:
	Prostokat(string opis, int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	string Nazwa()
	{
		return "Prostokat";
	}
	int PolePowierzchni()
	{
		return a*b;
	}
	double Obwod()
	{
		return 2 * a + 2 * b;
	}
};


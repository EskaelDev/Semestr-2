#pragma once
#include "Figura.h"
class Kwadrat :
	public Figura
{
	int a;
public:
	Kwadrat(string opis, int a)
	{
		this->a = a;
	}
	string Nazwa()
	{
		return "Kwadrat";
	}
	int PolePowierzchni()
	{
		return pow(a, 2);
	}
	double Obwod()
	{
		return 4*a;
	}
};


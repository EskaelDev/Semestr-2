#pragma once
#include "Nosnik.h"
class Plyta :
	public Nosnik
{
	string opis;
public:
	Plyta(string opis)
	{
		if (opis == "Plyta")
			this->opis = opis;
	}
	~Plyta();
};


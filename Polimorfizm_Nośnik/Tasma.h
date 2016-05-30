#pragma once
#include "Nosnik.h"
class Tasma :
	public Nosnik
{
	string opis;
	
public:
	Tasma(string opis)
	{
		if (opis == "Tasma")
			this->opis = opis;
	}
	~Tasma();
};


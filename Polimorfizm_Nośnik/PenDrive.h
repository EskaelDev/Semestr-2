#pragma once
#include "Nosnik.h"
class PenDrive :
	public Nosnik
{
	string opis;
public:
	PenDrive(string opis)
	{
		if (opis == "PenDrive")
			this->opis = opis;
	}
	~PenDrive();
};


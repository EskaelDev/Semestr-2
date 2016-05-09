#pragma once
#include "Cyfra.h"
class CyfraLCD :public Cyfra
{
public:
	CyfraLCD();
	CyfraLCD(int cyfra);
	void Wyswietl() const;
	~CyfraLCD();
};


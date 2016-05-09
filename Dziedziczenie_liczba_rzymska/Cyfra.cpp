#include "Cyfra.h"
#include <iostream>


Cyfra::Cyfra(int c)
{
	if (c < 0) 
		cyfra = 0;
	else if (c > 9) 
		cyfra = 9;
	else
		cyfra = c;
}

int const Cyfra::getCyfra() const
{
	return cyfra;
}

void Cyfra::Zmien(int c)
{
	if (c < 0) 
		cyfra = 0;
	else if (c > 9) 
		cyfra = 9;
	else
		cyfra = c;
}

void const Cyfra::Wyswietl() const
{
	std::cout << cyfra << " ";
}


Cyfra::~Cyfra()
{
}

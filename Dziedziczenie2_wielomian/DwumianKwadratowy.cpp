#include "DwumianKwadratowy.h"
#include <iostream>


DwumianKwadratowy::DwumianKwadratowy():
	WielomianWeWy(2)
{
	
}

inline float DwumianKwadratowy::Delta()
{
	return pow(Wielomian::Wspolczynnik(1), 2) - 4 * Wielomian::Wspolczynnik(2) * Wielomian::Wspolczynnik(0);
}

void DwumianKwadratowy::Wyswietl()
{
	WielomianWeWy::Wyswietl();
	std::cout << "x1= " << Wielomian::Wspolczynnik(1) + sqrt(Delta()) / Wielomian::Wspolczynnik(2) <<
				" x2= " << Wielomian::Wspolczynnik(1) - sqrt(Delta()) / Wielomian::Wspolczynnik(2) << std::endl;
}

DwumianKwadratowy::~DwumianKwadratowy()
{
}

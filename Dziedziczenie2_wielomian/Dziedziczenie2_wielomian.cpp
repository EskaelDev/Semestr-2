// Dziedziczenie2_wielomian.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DwumianKwadratowy.h"
#include <conio.h>
#include <iostream>

int main()
{
	Wielomian pierwszy_wielomian(4);
	WielomianWeWy pierwszy_wielomian_we_wy(3);
	DwumianKwadratowy siedem;


/*	pierwszy_wielomian_we_wy.Wprowadz();
	pierwszy_wielomian_we_wy.Wprowadz();
	pierwszy_wielomian_we_wy.Wprowadz();
	pierwszy_wielomian_we_wy.Wprowadz();


	pierwszy_wielomian_we_wy.Wyswietl();*/
	siedem.Ustaw(0, 0);
	siedem.Ustaw(1, 1);
	siedem.Ustaw(2, 2);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << siedem.Delta();
	std::cout << std::endl;

	siedem.Wyswietl();

	getch();

    return 0;
}


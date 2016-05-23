// Polimorfizm_Figura.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include "Figura.h"
#include "Elipsa.h"
#include "Kolo.h"
#include "Kwadrat.h"
#include "Prostokat.h"

using namespace std;


int main()
{
	string l;
	int licznik = 0;
	fstream plik;

	plik.open("plik.txt", ios::in);
	if (plik.good() == false)
		cout << "Blad otwarcia pliku" << endl;
	while (getline(plik, l))
	{
		licznik++;
	}
	plik.close();

	Figura *tablica[10];
	string linia;
	plik.open("plik.txt", ios::in);
	if (plik.good() == false)
		cout << "Blad otwarcia pliku" << endl;
	else
		for (int i = 0; i < (licznik / 2) - 1; i++)
		{
			int buff1, buff2;
			plik >> linia;
			if (linia == "prostokat")
			{
				plik >> buff1;
				plik >> buff2;
				tablica[i] = new Prostokat(linia, buff1, buff2);
			}
			else if (linia == "kwadrat")
			{
				plik >> buff1;
				tablica[i] = new Kwadrat(linia, buff1);
			}
			else
			if (linia == "kolo")
			{
				plik >> buff1;
				tablica[i] = new Kolo(linia, buff1);

			}
			else
			if (linia == "elipsa")
			{
				plik >> buff1;
				plik >> buff2;
				tablica[i] = new Elipsa(linia, buff1, buff2);
			}
			i++;
		}

	plik.close();
	for (int i = 0; i < 16; i++)
	{
		cout << tablica[i]->Nazwa() << " Obwod: " << tablica[i]->Obwod() << " Pole: " << tablica[i]->PolePowierzchni() << endl;
		i++;
	}
	getch();
    return 0;
}


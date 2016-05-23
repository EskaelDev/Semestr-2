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

	Figura *tablica;

    return 0;
}


// Zawieranie Kod_Pocztowy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

class KodPocztowy
{
	int czlon1, czlon2;
public:
	char tab[7];
	KodPocztowy();
	KodPocztowy(int, int);
	void scalanie(char*);
};

KodPocztowy::KodPocztowy()
{
	czlon1 = 00;
	czlon2 = 000;
}

KodPocztowy::KodPocztowy(int c1, int c2)
{
	if(!(c1>=100 || c1<=0 || c2>=1000 || c2<=0))
	{
		czlon1 = c1;
		czlon2 = c2;
	}
	else
	{
		czlon1 = 00;
		czlon2 = 000;
	}
}

void KodPocztowy::scalanie(char* tab)
{
	int jednosci = this->czlon1 % 10;
	int dziesiatki = (this->czlon1 -jednosci) / 10;

	tab[0] = dziesiatki;
	tab[1] = jednosci;
	tab[2] = '-';

	jednosci = this->czlon2 % 10;
	dziesiatki = ((this->czlon2 - jednosci) % 100) / 10;
	int setki = (this->czlon2 - (10 * dziesiatki) - jednosci) / 100;
	tab[3] = setki;
	tab[4] = dziesiatki;
	tab[5] = jednosci;
}

class Adres
{
	char NazwaUlicy[30], NumerBudynku[3], NumerLokalu[3], NazwaMiasta[40], adres[7];
	char kodPocztowy[7];
public:
	Adres(char*, char*, char*, char*, char*);
	char* WypiszNazwaUlicy();
	char* WypiszNumerBudynku();
	char* WypiszNumerLokalu();
	char* WypiszNazwaMiasta();
	char* WypiszAdres();
	char* WypiszKodPocztowy();
};

Adres::Adres(char* nazwaulicy, char* numerbudynku, char* numerlokalu, char* nazwamiasta, char* kodpocztowy)
{
	strcpy(NazwaUlicy, nazwaulicy);
	strcpy(NumerBudynku, numerbudynku);
	strcpy(NumerLokalu, numerlokalu);
	strcpy(NazwaMiasta, nazwamiasta);
	strcpy(kodPocztowy, kodpocztowy);
}

char* Adres::WypiszAdres()
{
	return adres;
}

char* Adres::WypiszNazwaMiasta()
{
	return NazwaMiasta;
}

char* Adres::WypiszNazwaUlicy()
{
	return NazwaUlicy;
}

char* Adres::WypiszNumerBudynku()
{
	return NumerBudynku;
}

char* Adres::WypiszNumerLokalu()
{
	return NumerLokalu;
}

char* Adres::WypiszKodPocztowy()
{
	return kodPocztowy;
}


int main()
{
	KodPocztowy kod(77, 145);
	kod.scalanie(kod.tab);
	Adres adres("Dekadentow", "1", "5", "Gliwice", kod.tab);


	cout << adres.WypiszNazwaMiasta() << " " << adres.WypiszNazwaMiasta() << " " << adres.WypiszNazwaUlicy() << " "
		<< adres.WypiszNumerBudynku() << adres.WypiszNumerLokalu() << " " << adres.WypiszKodPocztowy() << " " << endl;


	_getch();
    return 0;
}


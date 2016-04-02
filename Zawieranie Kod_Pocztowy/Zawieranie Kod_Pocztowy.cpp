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
	string NazwaUlicy, NumerBudynku, NumerLokalu, NazwaMiasta, adres;
	char kodPocztowy[7];
public:
	Adres(string, string, string, string, char*);
	string WypiszNazwaUlicy() const;
	string WypiszNumerBudynku()const;
	string WypiszNumerLokalu()const;
	string WypiszNazwaMiasta()const;
	string WypiszAdres()const;
	char* WypiszKodPocztowy();
};

Adres::Adres(string nazwaulicy, string numerbudynku, string numerlokalu, string nazwamiasta, char* kodpocztowy)
{
	NazwaMiasta = nazwamiasta;
	NazwaUlicy = nazwaulicy;
	NumerBudynku = numerbudynku;
	NumerLokalu = numerlokalu;
	strcpy(kodPocztowy, kodpocztowy);
}

string Adres::WypiszAdres()const
{
	return adres;
}

string Adres::WypiszNazwaMiasta()const
{
	return NazwaMiasta;
}

string Adres::WypiszNazwaUlicy()const
{
	return NazwaUlicy;
}

string Adres::WypiszNumerBudynku()const
{
	return NumerBudynku;
}

string Adres::WypiszNumerLokalu()const
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
	Adres adres("Reymonta", "8", "5", "Sosnowiec", kod.tab);


	cout << adres.WypiszNazwaMiasta() << " " << adres.WypiszNazwaMiasta() << " " << adres.WypiszNazwaUlicy() << " "
		<< adres.WypiszNumerBudynku() << adres.WypiszNumerLokalu() << " " << adres.WypiszKodPocztowy() << " " << endl;


	_getch();
    return 0;
}


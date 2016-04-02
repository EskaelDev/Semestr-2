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
	void ZerujTablice(char*);
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
	ZerujTablice(tab);
}

KodPocztowy::KodPocztowy(int c1, int c2)
{
	ZerujTablice(tab);
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

	tab[0] = dziesiatki+48;
	tab[1] = jednosci + 48;
	tab[2] = '-';

	jednosci = this->czlon2 % 10;
	dziesiatki = ((this->czlon2 - jednosci) % 100) / 10;
	int setki = (this->czlon2 - (10 * dziesiatki) - jednosci) / 100;
	tab[3] = setki + 48;
	tab[4] = dziesiatki + 48;
	tab[5] = jednosci + 48;
}
void KodPocztowy::ZerujTablice(char *tab)
{
	for (int i = 0; i < 7; i++)
	{
		tab[i] = '\0';
	}
}

class Adres
{
	char NazwaUlicy[40], NumerBudynku[3], NumerLokalu[3], NazwaMiasta[40], adres[7];
	char kodPocztowy[7];
	void ZerujTablice(char*, char*, char*, char*);
public:
	Adres(char*, char*, char*, char*, char*);
	char* WypiszNazwaUlicy();
	char* WypiszNumerBudynku();
	char* WypiszNumerLokalu();
	char* WypiszNazwaMiasta();
	char* WypiszAdres();
	char* WypiszKodPocztowy();
	
};

void Adres::ZerujTablice(char* ulica, char* budynek, char* lokal, char* miasto)
{
	for (int i = 0; i < 40; i++)
	{
		NazwaMiasta[i] = '\0';
		NazwaUlicy[i] = '\0';
	}
	for (int i = 0; i < 5; i++)
	{
		NumerBudynku[i] = '\0';
		NumerLokalu[i] = '\0';
	}
	for (int i = 0; i < 7; i++)
		kodPocztowy[i] = '\0';
}

Adres::Adres(char* nazwaulicy, char* numerbudynku, char* numerlokalu, char* nazwamiasta, char* kodpocztowy)
{
	ZerujTablice(NazwaUlicy, NumerBudynku, NumerLokalu, NazwaMiasta);
	strcat(NazwaUlicy, nazwaulicy);
	strcat(NumerBudynku, numerbudynku);
	strcat(NumerLokalu, numerlokalu);
	strcat(NazwaMiasta, nazwamiasta);
	strcat(kodPocztowy, kodpocztowy);
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


	cout << adres.WypiszNazwaMiasta() << " " << " " << adres.WypiszNazwaUlicy() << " "
		<< adres.WypiszNumerBudynku() << " " << adres.WypiszNumerLokalu() << " " << adres.WypiszKodPocztowy() << " " << endl;


	_getch();
    return 0;
}


// Zawieranie Numer_telefonu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include  <iostream>

using namespace std;

enum TypNumeru
{
	cell,
	home,
	job
};
class NumerTelefonu
{
	TypNumeru typ;
	unsigned short int NumerKierunkowy;
	string Numer;

public:
	NumerTelefonu(TypNumeru, unsigned short int, string);
	int WypiszKierunkowy();
	string WypiszNumer();
};

int NumerTelefonu::WypiszKierunkowy()
{
	return NumerKierunkowy;
}

string NumerTelefonu::WypiszNumer()
{
	return Numer;
}

class Kontakt
{
	string Imie, Nazwisko, Numer1, Numer2, Numer3, Numer4, Numer5;
public:
	Kontakt(string, string);

};


int main()
{
	
    return 0;
}


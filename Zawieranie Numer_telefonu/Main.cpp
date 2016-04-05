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
	unsigned short int NumerKierunkowy;
	void ZerowanieNumeru(char*);
	char Numer[10];

public:
	TypNumeru Typ;
	NumerTelefonu(TypNumeru, unsigned short int, char*);
	int WypiszKierunkowy();
	char* WypiszNumer();
};

void NumerTelefonu::ZerowanieNumeru(char* tab)
{
	for (int i = 0; i < 10; i++)
		tab[i] = '\0';
}

NumerTelefonu::NumerTelefonu(TypNumeru typ, unsigned short numerkierunkowy, char* tab)
{
	ZerowanieNumeru(Numer);
	Typ = typ;
	NumerKierunkowy = numerkierunkowy;
	strcat(Numer, tab);
}

int NumerTelefonu::WypiszKierunkowy()
{
	return NumerKierunkowy;
}

char* NumerTelefonu::WypiszNumer()
{
	return Numer;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Kontakt
{
	char Imie[20], Nazwisko[20], Numer[1][7];
	void ZerowanieNumerow();
	void ZerowanieNazwisk();
public:
	Kontakt(char*, char*, char*, char*, char*, char*, char*, NumerTelefonu*);
	void ScalImieNazwisko(char*);
	NumerTelefonu tabnr[5];
	
};


int main()
{
	
    return 0;
}


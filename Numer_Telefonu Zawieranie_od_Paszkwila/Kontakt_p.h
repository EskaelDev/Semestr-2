#pragma once
#include "NumerTelefonu_p.h"

class Kontakt_p
{
	char Imie[20];
	char Nazwisko[20];
	NumerTelefonu_p* Tabnr[5];
	char ImieNazwisko[41];

public:
	Kontakt_p(char*, char*);
	char* WypiszImieNazwisko();
	void UstawNumer(int, NumerTelefonu_p* telefon = NULL);
	void Zeruj(char*, int);
	void Wypisznumer(int);

	~Kontakt_p(void);
};


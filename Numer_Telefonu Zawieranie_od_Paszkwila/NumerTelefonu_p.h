#pragma once

#include <iostream>

class NumerTelefonu_p
{
	int Kierunkowy;
	char Numer[10];

public:
	enum Type {KOMORKOWY, DOMOWY, SLUZBOWY};
	Type typ;
	NumerTelefonu_p();
	NumerTelefonu_p(int, char*, Type);

	void ZerujNumer(char*, int);
	char* WypiszPelnyNumer(int, char*, Type);
	int ZwrocKierunkowy();
	char* ZwrocNumer();
	char* ZwrocTyp();

	~NumerTelefonu_p(void);
};


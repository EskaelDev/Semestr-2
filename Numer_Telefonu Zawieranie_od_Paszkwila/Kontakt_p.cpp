#include "Kontakt_p.h"
#include "NumerTelefonu_p.h"
#include <iostream>

using namespace std;


Kontakt_p::Kontakt_p(char* tabi, char* tabn)
{
	Zeruj(Imie, 20);
	Zeruj(Nazwisko, 20);

	strcpy(Imie, tabi);
	strcpy(Nazwisko, tabn);

	for (int i = 0; i < 5; i++)
	{
		Tabnr[i] = new NumerTelefonu_p();
	}
}

void Kontakt_p::Zeruj(char* tablica, int n)
{
	for (int i = 0; i < n; i++)
		tablica[i] = '\0';
}

char* Kontakt_p::WypiszImieNazwisko()
{
	Zeruj(ImieNazwisko, 41);
	strcat(ImieNazwisko, Imie);
	strcat(ImieNazwisko, " ");
	strcat(ImieNazwisko, Nazwisko);
	return ImieNazwisko;
}

void Kontakt_p::UstawNumer(int id, NumerTelefonu_p* numertelefonu)
{
	if (id <= 5 && id >= 0)
		if (numertelefonu == NULL)
			Tabnr[id] = NULL;
		else
			Tabnr[id] = numertelefonu;
}

void Kontakt_p::Wypisznumer(int id)
{
	if (id <= 5 && id >= 0 && Tabnr[id]!=NULL)
	{
		std::cout << Tabnr[id]->ZwrocKierunkowy() << " " <<
			Tabnr[id]->ZwrocNumer() << " " << Tabnr[id]->ZwrocTyp() << std::endl;

	}
}



Kontakt_p::~Kontakt_p(void)
{
}

// Przeci¹¿anie operatorów DynString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dyn_String.h"
#include <conio.h>



int main()
{
	Dyn_String napis("Napis testowy");
	printf("Napis : %s\n", napis.Cstr());
	printf("Znakow : %u\n", napis.Size());

	Dyn_String kopia = napis;
	printf("\nKopia : %s\n", kopia.Cstr());
	printf("Znakow : %u\n", kopia.Size());

	kopia += " - pierwszy fragment - ";
	kopia += " drugi fragment.";

	printf("\nNapis : %s\n", napis.Cstr());
	printf("Znakow : %u\n", napis.Size());
	printf("\nKopia : %s\n", kopia.Cstr());
	printf("Znakow : %u\n", kopia.Size());

	!napis;
	printf("\nNapis : %s\n", napis.Cstr());

	printf("\nKoniec.");
	_getch();


    return 0;
}


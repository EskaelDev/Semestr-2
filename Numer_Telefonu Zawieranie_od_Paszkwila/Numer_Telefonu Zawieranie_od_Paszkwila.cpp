// Numer_Telefonu Zawieranie_od_Paszkwila.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>
#include "Kontakt_p.h"

using namespace std;
			
int main()
{
	Kontakt_p* K = new Kontakt_p("Jan", "Uasica");
	K->UstawNumer(1, new NumerTelefonu_p(32, "7765433", NumerTelefonu_p::DOMOWY));
	K->UstawNumer(3, new NumerTelefonu_p(77, "555999232", NumerTelefonu_p::KOMORKOWY));
	cout << K->WypiszImieNazwisko();

	K->Wypisznumer(1);
	K->UstawNumer(1);

	K->Wypisznumer(3);
    return 0;
}


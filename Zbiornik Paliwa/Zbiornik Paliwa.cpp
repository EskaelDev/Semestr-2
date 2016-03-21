// Zbiornik Paliwa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;
class zbiornik_paliwa
{
	int p;
	int p_max;
public:
	zbiornik_paliwa(int max_p);
	int ile_p() const;
	bool czy_crit();
	bool tankowanie(int dolewa);
	int spalanie(int spala);
	bool awaryjne();
};

zbiornik_paliwa::zbiornik_paliwa(int max_p)
{
	p = 0;
	p_max = max_p;
}

bool zbiornik_paliwa::awaryjne()
{
	p = 0;
	return true;
}

int zbiornik_paliwa::ile_p() const
{
	return p;
}

bool zbiornik_paliwa::czy_crit()
{
	if (p <= 0.1*p_max)
		return true;
	else
		return false;
}

bool zbiornik_paliwa::tankowanie(int dolewa)
{
	if (dolewa > 0 && dolewa + p <= p_max)
	{
		p += dolewa;
		return true;
	}
	else
		return false;
}


int zbiornik_paliwa::spalanie(int spala)
{
	if (spala < 0)
		cout << "Podano zla wartosc" << endl;
	else
		if (p - spala < 0)
		{
			p = 0;
			cout << "Iloœæ paliwa: " << p << endl;
		}
		else
		{
			p -= spala;
			cout << "Iloœæ paliwa: " << p << endl;
		}
	return 0;
}




int main()
{
	int max_p=0;
	bool koniec=true;
	for (;;)
	{
		cout << "Podaj wielkosc zbiornika" << endl;
		cin >> max_p;
		if (max_p <= 5)
			cout << "Zla wartosc" << endl;
		else
			break;
	}

	zbiornik_paliwa bak(max_p);
	int w;


	while(koniec)
	{
		cout <<
			"\nCo chcesz zrobic?" << endl <<
			"1. Dolej paliwa" << endl <<
			"2. Zuzyj paliwo?   co kurwa?" << endl <<
			"3. Koniec" << endl <<
			"Wybieram: " << endl;
		cin >> w;

		switch(w)
		{
		case 1: 
			int wlew;
			cout << "\nIle paliwa chcesz dolac: " << endl;
			cin >> wlew;
			if (bak.tankowanie(wlew))
				cout << "Tankowanie zakonczone powodzeniem" << endl;
			else
				cout << "Podana zostala zla wartosc" << endl;
			break;

		case 2:
			int spala;
			cout << "Ile paliwa chcesz pobrac: " << endl;
			cin >> spala;
			bak.spalanie(spala);
			break;
		case 3:
		{
			koniec = false;
			break;
		}
		default: 
		{
			cout << "Zla wartosc" << endl;
			break;
		}

		}
	
		system("cls");

		cout <<
			"Jest " << bak.ile_p() << " paliwa" << endl;
		if (bak.czy_crit())
			cout << "\n_-_-_-!*POZIOM KRYTYCZNY ERROR KURWA ERROR*!-_-_-_\n" << endl;

	}

	_getch();
    return 0;
}


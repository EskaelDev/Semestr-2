// Klasy Ekspres_do_kawy_brak_numeru.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

class ekspres
{
	int mleko, woda, max_w, max_m;
	
public:
	int sprawdz_pojemnosc_zbiornika_wody() const;
	int sprawdz_pojemnosc_zbiornika_mleka() const;
	int sprawdz_stan_zbiornika_wody() const;
	int sprawdz_stan_zbiornika_mleka() const;
	bool dolej_mleka(int ilosc_mleka);
	bool dolej_wody(int ilosc_wody);
	bool przygotuj_czarna();
	bool przygotuj_biala();
	bool przygotuj_espreso();
	ekspres(int w_max,int m_max);
};

ekspres::ekspres(int w_max, int m_max)
{
	woda = 0;
	mleko = 0;
	max_m = m_max;
	max_w = w_max;
}

int ekspres::sprawdz_pojemnosc_zbiornika_mleka() const
{
	return max_m;
}

int ekspres::sprawdz_pojemnosc_zbiornika_wody() const
{
	return max_w;
}

int ekspres::sprawdz_stan_zbiornika_mleka() const
{
	return mleko;
}

int ekspres::sprawdz_stan_zbiornika_wody() const
{
	return woda;
}

bool ekspres::dolej_mleka(int ilosc_mleka)
{
	if (ilosc_mleka > 0 && ilosc_mleka + mleko <= max_m)
	{
		mleko += ilosc_mleka;
		return true;
	}
	else
		return false;
}
bool ekspres::dolej_wody(int ilosc_wody)
{
	if (ilosc_wody > 0 && ilosc_wody + woda <= max_w)
	{
		woda += ilosc_wody;
		return true;
	}
	else
		return false;
}

bool ekspres::przygotuj_biala()
{
	if (mleko>=2 && woda>=3)
	{
		mleko -= 2;
		woda -= 3;
		return true;
	}
	else return false;
}

bool ekspres::przygotuj_czarna()
{
	if (woda>=5)
	{
		woda -= 5;
		return true;
	}
	return false;
}
bool ekspres::przygotuj_espreso()
{
	if(woda>=4 && mleko>=1)
	{
		woda -= 4;
		mleko -= 1;
		return true;
	}
	else return false;
}



int main()
{
	int pojemnosc_wody = 0, pojemnosc_mleka = 0;
	cout << "_-_-_  WITAJ W SYMULATORZE PICIA KAWY  _-_-_" << endl;

	for (;;)
	{
		cout << "Podaj pojemnosc zbiornika na wode: " << endl;
		cin >> pojemnosc_wody;
			if (pojemnosc_wody < 5)
				cout << "Podano bledna wartosc" << endl;
			else break;
	}
	
	for (;;)
	{
		cout << "Podaj pojemnosc zbiornika na mleko" << endl;
		cin >> pojemnosc_mleka;
		if(pojemnosc_mleka < 2)
			cout << "Podano bledna wartosc" << endl;
		else break;
	}
	ekspres Expres(pojemnosc_wody, pojemnosc_mleka);
	bool koniec = true;

	while (koniec)
	{
		int wybor=0;
		cout << "\n\nCo chcesz zrobic?" << endl <<
			"1 Sprawdz pojemnosc zbiornika na wode" << endl <<
			"2 Sprawdz pojemnosc zbiornika na mleko" << endl <<
			"3 Sprawdz ile jest wody w zbiorniku" << endl <<
			"4 Sprawdz ile jest mleka w zbiorniku" << endl <<
			"5 Dolej wody" << endl <<
			"6 Dolej mleka" << endl <<
			"7 Kawa czarna 7zl" << endl <<
			"8 Kawa biala 10zl" << endl <<
			"9 Kawa Espresso" << endl <<
			"10 Koniec" << endl <<
			"Wybieram bramke numer: " << endl;
		cout << "\n\n";
		cin >> wybor;
		switch(wybor)
		{
			case 1: 
			{
				cout << "Pojemnosc zbiornika na wode wynosi : " << Expres.sprawdz_pojemnosc_zbiornika_wody() << endl;
				_getch();
				break; 
			}

			case 2: 
			{
				cout << "Pojemnosc zbiornika na mleko wynosi : " << Expres.sprawdz_pojemnosc_zbiornika_mleka() << endl;
				_getch();
				break;
			}
			case 3:
			{
				cout << "Jest " << Expres.sprawdz_stan_zbiornika_wody() << " wody w zbiorniku" << endl;
				_getch();
				break;
			}
			
			case 4:
			{
				cout << "Jest " << Expres.sprawdz_stan_zbiornika_mleka() << " mleka w zbiorniku" << endl;
				_getch();
				break;
			}

			case 5:
			{
				int do_wlania;
				cout << "Ile wody chcesz dolac: " << endl;
				cin >> do_wlania;
				if (Expres.dolej_wody(do_wlania))
					cout << "Dolano " << do_wlania << " wody" << endl;
				else
					cout << "Podales zbyt duza lub zbyt mala liczbe cfelu" << endl <<
					"Naucz sie liczyc pajacu" << endl;
				_getch();
				break;
			}
			case 6:
			{
				int do_wlania;
				cout << "Ile mleka chcesz dolac: " << endl;
				cin >> do_wlania;
				if(Expres.dolej_mleka(do_wlania))
					cout << "Dolano " << do_wlania << " mleka" << endl;
				else
					cout << "Podales zbyt duza lub zbyt mala liczbe cfelu" << endl <<
					"Naucz sie liczyc pajacu" << endl;
				_getch();
				break;
			}
			case 7:
			{
				if (Expres.przygotuj_czarna())
					cout << "Przygotowano kawe czarna\n udlaw sie " << endl;
				else
					cout << "Za malo wody w piekarniku" << endl;
				_getch();
				break;
			}
			case 8: 
			{
				if (Expres.przygotuj_biala())
					cout << "Przygotowano kawe biala" << endl;
				else
					cout << "Za malo skladnikow do przyrzadzenia tej starozytnej mikstury" << endl;
				_getch();
				break;
			}
			case 9:
			{
				if (Expres.przygotuj_espreso())
					cout << "Przygotowano kawe espresso\nstudnecie prawa..." << endl;
				else 
					cout << "Za malo pieprzu lub wody/mleka\nowocioto" << endl;
				_getch();
				break;
			}
			case 10:
			{
				koniec = false;
				break;
			}
			default:
			{
				cout << "Nie ma takiej opcji w menu\naucz sie czytac " << endl;
				break;
			}

		}

	}

	_getch();
return 0;
}


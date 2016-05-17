#include "WielomianWeWy.h"
#include <iostream>

using namespace std;


WielomianWeWy::WielomianWeWy(int s):Wielomian(s)
{
}

void WielomianWeWy::Wprowadz()
{
	int a, i;
	cout << "\n" << Wielomian::Stopien() << endl;
	cout << "Ktory wspolczynnik zmienic? ";
	cin >> i;
	cout << "Jaka wartosc ustawic? ";
	cin >> a;
	Wielomian::Ustaw(i, a);
}

void WielomianWeWy::Wyswietl()
{
	for (int i = 0; i < Wielomian::Stopien() + 1; i++)
	{
		cout << Wielomian::Wspolczynnik(Wielomian::Stopien() - i) << "_" << Wielomian::Stopien() << "*x^" << Wielomian::Stopien();
		if (i != Wielomian::Stopien())
			cout << " + ";
		else
			cout << " = y" << endl;
	}
}


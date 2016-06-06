// Wyj¹tki_2_Stos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "Stos.h"


using namespace std;
int main()
{
	Stos *s;
	unsigned int wybor;
	do
	{
		system("cls");
		cout << " --- MENU ---" << endl;
		cout << "1. Utworzenie stosu" << endl;
		cout << "2. Wyswietlenie stosu" << endl;
		cout << "3. Dodanie elementu" << endl;
		cout << "4. Zdjecie elementu" << endl;
		cout << "5. Element najmniejszy" << endl;
		cout << "6. Koniec programu " << endl;
		cout << "Wybierz : ";
		cin >> wybor;
		switch (wybor)
		{
		case 1:
		{
			int tmp;
			cout << "Podaj rozmiar stosu" << endl;
			while(cin>>tmp)
			{
				try
				{
					s = new Stos(tmp);
					break;
				}
				catch (NiepoprawnaAlokacja &e)
				{
					cout << e.what() << endl;
					cout << "Wprowadz jeszcze raz dane" << endl;
					continue;
				}
			}
			break;
		}
		case 2:
		{
			try
			{
				s->WyswietlStos();
			}
			catch (StosPusty & e)
			{
				cout << e.what() << endl;
			}
			break;
		}
		case 3:
		{
			int temp1;
			std::cout << "Wprowadz dane:";
			cin >> temp1;
			try
			{
				s->Odloz(temp1);
			}
			catch (BrakMiejsc & e)
			{
				cout << e.what() << endl;
				cout << "Najpierw usun cos ze stosu" << endl;

			}

			break;
		}
		case 4:
			try
			{
				s->Pobierz();
			}
			catch (StosPusty & e)
			{
				cout << e.what() << endl;
			}
			break;
		case 5:
			try
			{
				cout << " Najmniejsza wartosc: " << s->Minimum() << endl;
			}
			catch (StosPusty & e)
			{
				cout << e.what() << std::endl;
			}

			break;
		}

	} while (wybor != 6);

	return 0;
}


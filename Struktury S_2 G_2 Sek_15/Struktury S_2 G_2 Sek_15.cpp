// Struktury S_2 G_2 Sek_15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>

/*
using namespace std;


struct ryby
{ 
	string gatunek;
	float polow;
};


int main()
{
	//string wyraz;
	cout << "Podaj tekst: ";
	cin >> wyraz;
	cout << "Wprowadziles: \"" << wyraz << "\"" << endl;
	//cout << "D³ugosc wyrazu: " << wyraz.length() << endl;


	ifstream plik2("S:\plik.txt");
	FILE *plik;
	if ((plik = fopen("S:\plik.txt", "r")) == NULL)
		cout << "nie otwarto pliku" << endl;
	if (!plik2)
	{
		cout << "nie otwarto pliku.\n";
		getch();
		return 0;
	}
	while (plik2.good())
	{
		bool pom;
		string buff;
		int i = 0, lp = 1;
		float polowy = 0;
		ryby *tab = new ryby[100];

		while (!feof(plik)) 
		{
			getline(plik2, buff, ' ');
			if (buff != "")
			{
				tab[i].gatunek = buff;
			}
			fscanf(plik, "%f", &tab[i++].polow);
		}
	
	//FILE *plik;
	if ((plik = fopen("S:\plik.txt", "r")) == NULL)
		cout << "nie otwarto pliku" << endl;
	else
	{
		bool pom;
		int i = 0, lp = 1;
		float polowy = 0;
		ryby *tab = new ryby[100];

		while (!feof(plik))
		{
			getline (plik, tab[i].gatunek );
			fscanf(plik, "%f", &tab[i++].polow);
		//}


		//sumwanie tych samych//
		for (int j = 0; j < i; j++)
			for (int k = j + 1; k < i; k++)
				if (tab[j].gatunek.compare(tab[k].gatunek))
					tab[j].polow += tab[k].polow;



		 for (int j = 0; j < i; j++)
		{
			pom = true;
			if (j > 0) 
			{
				for (int k = 0; k < j; k++)
				{
					if (tab[j].gatunek.compare(tab[k].gatunek)) 
						pom = false;
				}
				if (pom)
				{
					cout << lp + 1 << " " << tab[j].gatunek << " " << tab[j].polow << endl;
					lp++;
				}
			}
			else cout << lp << " " << tab[j].gatunek << " " << tab[j].polow << endl;
		}

		delete tab;
		fclose(plik);
	}
	_getch();
    return 0;
}*//*
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>


using namespace std;


struct ryby
{
	string gatunek;
	float polow;
};


int main()
{
	FILE *plik;
	if ((plik = fopen("S:\plik.txt", "r")) == NULL)
		cout << "nie otwarto pliku" << endl;
	else
	{
		bool pom;
		int i = 0, lp = 1;
		float polowy = 0;
		ryby *tab = new ryby[100];

		while (!feof(plik))
		{
			fscanf(plik, "%s", tab[i].gatunek.c_str());
			fscanf(plik, "%f", &tab[i++].polow);
		}


		//sumwanie tych samych/////
		for (int j = 0; j < i; j++)
			for (int k = j + 1; k < i; k++)
				if (tab[j].gatunek.compare(tab[k].gatunek))
					tab[j].polow += tab[k].polow;


		for (int j = 0; j < i; j++)
		{
			pom = true;
			if (j > 0)
			{
				for (int k = 0; k < j; k++)
				{
					if (tab[j].gatunek.compare(tab[k].gatunek))
						pom = false;
				}
				if (pom)
				{
					cout << lp + 1 << " " << tab[j].gatunek << " " << tab[j].polow << endl;
					lp++;
				}
			}
			else cout << lp << " " << tab[j].gatunek << " " << tab[j].polow << endl;
		}

		delete tab;
		fclose(plik);
	}
	_getch();
	return 0;
}*/
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <windows.h>


using namespace std;

void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}



struct ryby
{
	char gatunek[18];
	float polow;
};


int main()
{
	SetWindow(200, 75);
	FILE *plik;
	if ((plik = fopen("S:\plik.txt", "r")) == NULL)
		cout << "nie otwarto pliku" << endl;
	else
	{
		bool pom;
		int i = 0, lp = 1;
		float polowy = 0;
		ryby *tab = new ryby[100];

		while (!feof(plik))
		{
			fscanf(plik, "%s", &tab[i].gatunek);
			fscanf(plik, "%f", &tab[i++].polow);
		}


		//sumwanie tych samych/////
		for (int j = 0; j < i; j++)
			for (int k = j + 1; k < i; k++)
				if (!strcmp(tab[j].gatunek, tab[k].gatunek))
					tab[j].polow += tab[k].polow;


		for (int j = 0; j < i; j++)
		{
			pom = true;
			if (j > 0)
			{
				for (int k = 0; k < j; k++)
				{
					if (!strcmp(tab[j].gatunek, tab[k].gatunek))
						pom = false;
				}
				if (pom)
				{
					cout << lp + 1 << " " << tab[j].gatunek << " " << tab[j].polow << endl;
					lp++;
				}
			}
			else cout << lp << " " << tab[j].gatunek << " " << tab[j].polow << endl;
		}

		delete tab;
		fclose(plik);
	}
	_getch();
	return 0;
}
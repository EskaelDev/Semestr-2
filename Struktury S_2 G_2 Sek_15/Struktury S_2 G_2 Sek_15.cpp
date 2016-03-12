// Struktury S_2 G_2 Sek_15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
			fscanf(plik, "%s", &tab[i].gatunek);
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
}


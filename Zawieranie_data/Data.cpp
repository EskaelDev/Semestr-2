#include "Data.h"



Data::Data()
{
	Rok = 1970;
	Miesiac = 01;
	Dzien = 01;
}

Data::Data(int D, int M, int R)
{
	bool sukces = false;

	if (R >= 1970)
	{
		sukces = true;
	}

	if (M >= 1 && M <= 12)
	{
		sukces = true;
	}
	else
		sukces = false;

	if ((M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) && D >= 1 && D <= 31)
		sukces = true;
	else
		if ((M == 4 || M == 6 || M == 9 || M == 11) && D >= 1 && D <= 30)
			sukces = true;
		else if (M == 2 && D >= 1 && D <= 29)
			sukces = true;
		else
			sukces = false;

		if (sukces)
		{
			Rok = R;
			Miesiac = M;
			Dzien = D;
		}
}

int Data::WypiszDzien() const
{
	return Dzien;
}

int Data::WypiszMiesiac() const
{
	return Miesiac;
}

int Data::WypiszRok() const
{
	return Rok;
}

void Data::ZmienDate(int D, int M, int R)
{
	bool sukces = false;

	if (R >= 1970)
	{
		sukces = true;
	}

	if (M >= 1 && M <= 12)
	{
		sukces = true;
	}
	else
		sukces = false; 

	if ((M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) && D >= 1 && D <= 31)
		sukces = true;
	else
		if ((M == 4 || M == 6 || M == 9 || M == 11) && D >= 1 && D <= 30)
			sukces = true;
		else if (M == 2 && D >= 1 && D <= 29)
			sukces = true;
		else
		sukces = false;

	if(sukces)
	{
	Rok = R;
	Miesiac = M;
	Dzien = D;
	}
}

void Data::Zeruj(char* tab)
{
	for (int i = 0; i < 10; i++)
		tab = '\0';

}


char* Data::PelnaData(int D, int M, int R)
{
	char tab[10];
	Zeruj(tab);

	int jednosci = D % 10;
	int dziesiatki = ((D % 100) - jednosci) / 10;
	
	tab[0] = dziesiatki + 48;
	tab[1] = jednosci + 48;
	tab[2] = '-';

	jednosci = M % 10;
	dziesiatki = ((M % 100) - jednosci) / 10;
	tab[3] = dziesiatki + 48;
	tab[4] = jednosci + 48;
	tab[5] = '-';
	 // 1970
	jednosci = R % 10;
	dziesiatki = ((R%100) - jednosci) / 10;
	int setki = ((R%1000) - dziesiatki - jednosci) / 100;
	int tysiace = ((R%1000) - setki - dziesiatki - jednosci) / 1000;
	tab[6] = dziesiatki + 48;
	tab[7] = jednosci + 48;
	tab[8] = setki + 48;
	tab[9] = tysiace + 48;

	return tab;
}


Data::~Data(void)
{
}

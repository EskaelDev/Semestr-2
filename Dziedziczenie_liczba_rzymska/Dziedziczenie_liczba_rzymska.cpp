// Dziedziczenie_liczba_rzymska.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include "Cyfra.h"
#include "CyfraRzymska.h"
#include "CyfraLCD.h"


int main()
{
	Cyfra zero(0);
	Cyfra osiem(8);
	Cyfra piec(5);
	CyfraRzymska jeden(1);
	CyfraRzymska dziewiec(35);
	CyfraLCD trzy(3);
	CyfraLCD zero1(-21);
	CyfraLCD siedem(7);
	zero.Wyswietl();
	osiem.Wyswietl();
	piec.Wyswietl();
	jeden.Wyswietl();
	dziewiec.Wyswietl();
	trzy.Wyswietl();
	zero1.Wyswietl();
	siedem.Wyswietl();

	_getch();

    return 0;
}


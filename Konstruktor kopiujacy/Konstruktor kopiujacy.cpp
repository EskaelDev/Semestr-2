// Konstruktor kopiujacy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "DynArray.h"
#include <conio.h>

using namespace std;


int main()
{
	const int tst_size1 = 20;
	const int tst_size2 = 50000;

	DynArray array1;
	printf("array1 size: %d\n", array1.size());
	printf("array1 disp: ");
	array1.display();

	DynArray array2;
	printf("array2 size: %d\n", array2.size());
	printf("array2 disp: ");
	array1.display();

	for (int i = 0; i < tst_size1; ++i)
	{
		array1.add(1);
	}
	printf("\narray1 size: %d\n", array1.size());
	printf("array1 disp: ");
	array1.display();

	DynArray array3(array1);
	printf("array3 size: %d\n", array3.size());
	printf("array3 disp: ");
	array3.display();

	printf("\n\nget test : ");
	for (int i = 0; i < array3.size(); ++i)
	{
		printf("%d ", array3.get(i));
	}

	for (int i = 0; i < tst_size2; ++i)
	{
		array1.add(1);
	}

	printf("\n\n");
	for (int i = array1.size() - 5; i < array1.size(); ++i)
	{
		printf("array1[%d] = %d\n", i, array1.get(i));
	}

	DynArray * arrayX = new DynArray(10, 1);
	arrayX->add(1000);
	DynArray arrayY(*arrayX);
	delete arrayX;

	printf("\n\narrayY size: %d\n", arrayY.size());
	printf("arrayY disp: ");
	arrayY.display();

	printf("\nKoniec.");
	_getch();

    return 0;
}


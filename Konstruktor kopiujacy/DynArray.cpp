#include "DynArray.h"
#include <iostream>

using namespace std;

DynArray::DynArray()
{
	rozmiar = 0;
}

DynArray::DynArray(int N, int M)
{
	rozmiar = N;

	for (int i = 0; i < N;i++)
	{
		tab[i] = M;
	}
}

DynArray::DynArray(const DynArray &array)
{
	rozmiar = array.rozmiar;
	tab = new int[rozmiar];

	for (int i = 0; i < rozmiar;i++)
	{
		tab[i] = array.tab[i];
	}
}


int DynArray::size()
{
	return rozmiar;
}

void DynArray::display()
{
	for (int i = 0; i < rozmiar;i++)
	{
		cout<<
	}
}

void DynArray::add(int i)
{
	if (rozmiar>0)
	{
		int *tmp = new int[rozmiar];

	}
}

int DynArray::get(int i)
{
	return tab[i];
}


DynArray::~DynArray(void)
{
}

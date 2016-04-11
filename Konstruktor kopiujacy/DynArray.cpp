#include "DynArray.h"
#include <iostream>

using namespace std;

DynArray::DynArray()
{
	rozmiar = 0;
	tab = (int*)malloc(sizeof(int)*rozmiar);

}

DynArray::DynArray(int N, int M)
{
	rozmiar = N;

	tab = (int*)malloc(sizeof(int)*rozmiar);

	for (int i = 0; i < N;i++)
	{
		tab[i] = M;
	}
}

DynArray::DynArray(const DynArray& array)
{
	rozmiar = array.rozmiar;
	tab = (int*)malloc(sizeof(int)*rozmiar);

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
	cout << "[";
	for (int i = 0; i < rozmiar; i++)
	{
		cout << tab[i];
		if (i < rozmiar - 1)
			cout << ", ";
	}
	cout << "]";

}

void DynArray::add(int n)
{
	

		int *tmp = (int*)malloc(sizeof(int)*rozmiar);

		for (int i = 0; i < rozmiar; i++)
			tmp[i] = tab[i];

		rozmiar++;

		free(tab);
		tab = (int*)malloc(sizeof(int)*rozmiar);

		for (int i = 0; i < rozmiar; i++)
			tab[i] = tmp[i];
		tab[rozmiar-1] = n;
		free(tmp);
}

/*
void DynArray::add(int l)
{
	tab = (int*)realloc(tab, ++rozmiar * sizeof(int));
	tab[rozmiar - 1] = l;
}
*/

int DynArray::get(int i)
{
	return tab[i];
}


DynArray::~DynArray(void)
{
}

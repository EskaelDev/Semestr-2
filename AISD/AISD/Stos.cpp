// AISD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


struct Stos
{
	int capacity, size, data;
};

Stos* StworzStos(unsigned int Capacity)
{
	if(Capacity>0)
	{
		Stos *S = new Stos;
		S->capacity = Capacity;
		S->size = 0;
		S->data = 0;
		return S;
	}
	return 0;
}

void ZniszczStos(Stos **S)
{
	delete *S->data;
	delete S;
}

unsigned int Elementy(Stos *S)
{
	return S->size;
}

void Odloz(Stos **S, const int V)
{
	Stos *ns = new Stos;
	ns->data = V;
	if (*S==0)
	{
		*S = ns;
	}
	else
	{
		Stos *p = *S;

	}
}



int main()
{
	Stos *S = NULL;
	for (unsigned int i = 1; i <= 4; ++i)
	{
		Odloz(&S, 11 * i);
		printf("E = %d + %d\n", Elementy(5), 11 * i);
	}


	for (unsigned int i = 1; i <= 4; ++i)
	{
		printf("E = %d - %d\n", Elementy(5), Zdejmij($S));
	}
    return 0;
}


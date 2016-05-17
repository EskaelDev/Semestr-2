#include "Wielomian.h"
#include <math.h>


Wielomian::Wielomian(int n)
{
	if (n < 1)
		this->n = 1;
	else
		if (n > 100)
			this->n = 100;
		else
			this->n = n;

	a = new int[n+1];
	for (int i = 0; i < n+1; i++)
		a[i] = 0;
}

 int Wielomian::Stopien() const
{
	return n;
}

void Wielomian::Ustaw(int i, int a)
{
	this->a[i] = a;
}

float Wielomian::Wspolczynnik(int i) const
{
	return this->a[i];
}

float Wielomian::Wartosc(float x)
{
	float y;
	for (int i = 0; i < n+1; i++)
	{
		y += a[i] * pow(x, i);
	}
	return y;
}

Wielomian::~Wielomian()
{
	delete[] a;
}

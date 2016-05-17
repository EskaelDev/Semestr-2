#pragma once
class Wielomian
{
	int n, *a;

public:
	Wielomian(int n);
	int Stopien() const;
	void Ustaw(int i, int a);
	float Wspolczynnik(int i) const;
	float Wartosc(float x);

	~Wielomian();

};


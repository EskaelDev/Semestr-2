#pragma once
class DynArray
{

	int *tab, rozmiar;
public:
	DynArray();
	DynArray(int, int);
	DynArray(const DynArray &);
	
	int size();
	void display();
	void add(int);
	int get(int);

	~DynArray(void);
};


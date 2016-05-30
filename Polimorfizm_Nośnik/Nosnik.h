#pragma once
#include <iostream>

using namespace std;

class Nosnik
{
public:
	
	virtual string Nazwa() = 0;
	virtual int Pojemnosct() = 0;

	virtual ~Nosnik();
};


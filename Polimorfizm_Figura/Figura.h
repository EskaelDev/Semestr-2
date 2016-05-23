#pragma once
#include <iostream>
using namespace std;
class Figura
{
public:
	virtual string Nazwa() = 0;
	virtual int Obwod() = 0;
	virtual int PolePowierzchni() = 0;
};


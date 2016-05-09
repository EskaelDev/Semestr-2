#include "CyfraLCD.h"
#include <iostream>
using namespace std;


CyfraLCD::CyfraLCD() : Cyfra(0)
{
	
}

CyfraLCD::CyfraLCD(int cyfra) : Cyfra(cyfra)
{
	
}

void CyfraLCD::Wyswietl() const
{
	switch(getCyfra())
	{
	case 0: std::cout << endl
		<< "   ##   " << std::endl
		<< "  #  #  " << endl
		<< "  #  #  " << endl
		<< "  #  #  " << endl
		<< "   ##   ";
		break;
	case 1: std::cout << endl
		<< "    ##   " << std::endl
		<< "   # #  " << endl
		<< "  #  #  " << endl
		<< "     #   " << endl
		<< "     #   ";
		break;
	case 2: std::cout << endl
		<< "   ##   " << std::endl
		<< "  #  #  " << endl
		<< "    #   " << endl
		<< "   #    " << endl
		<< "  ####  ";
		break;
	case 3: std::cout << endl
		<< "   ##   " << std::endl
		<< "  #  #  " << endl
		<< "   ###  " << endl
		<< "  #  #  " << endl
		<< "   ##   ";
		break;
	case 4: std::cout << endl
		<< "  #  #  " << std::endl
		<< "  #  #  " << endl
		<< "  ####  " << endl
		<< "     #  " << endl
		<< "     #  ";
		break;
	case 5: std::cout << endl
		<< "  ####  " << std::endl
		<< "  #     " << endl
		<< "  ####  " << endl
		<< "  #  #  " << endl
		<< "   ##   ";
		break;
	case 6: std::cout << endl
		<< "    #   " << std::endl
		<< "  #    " << endl
		<< "  ###   " << endl
		<< "  #  #  " << endl
		<< "   ##   ";
		break;
	case 7: std::cout << endl
		<< "  ##### " << std::endl
		<< "     #  " << endl
		<< "   ###  " << endl
		<< "   #    " << endl
		<< "  #     ";
		break;
	case 8: std::cout << endl
		<< "   ###  " << std::endl
		<< "  #   # " << endl
		<< "    #   " << endl
		<< "  #   # " << endl
		<< "   ###  ";
		break;
	case 9: std::cout << endl
		<< "   ##   " << std::endl
		<< "  #  #  " << endl
		<< "  ####  " << endl
		<< "     #  " << endl
		<< "   ##   ";
		break;
	}
}


CyfraLCD::~CyfraLCD()
{
}

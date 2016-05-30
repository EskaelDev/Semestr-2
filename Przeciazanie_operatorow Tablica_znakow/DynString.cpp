#include "DynString.h"
#include <cstdlib>


DynString::DynString(char*)
{
	
}

DynString::DynString(DynString & cos)
{
	r = cos.r;
	tab = cos.tab;
}

int DynString::Size()
{
	return r;
}

char* DynString::CStr()
{
	return tab;
}

char* DynString::operator+=(char) 
{

	tab = (char*)realloc(tab, );
}

char* DynString::operator!() 
{

}




DynString::~DynString()
{
}

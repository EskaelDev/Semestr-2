#pragma once
#include <exception>

class BrakMiejsc :
	public std::exception
{
public:
	BrakMiejsc(){}
	const char* what() const throw()
	{
		return "Stos przepelniony.";
	}

};


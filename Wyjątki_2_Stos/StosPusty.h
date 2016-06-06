#pragma once
#include <exception>

class StosPusty	:
	public std::exception
{
public:
	StosPusty(){}
	const char* what() const throw()
	{
		return "Pusty stos!";
	}
};


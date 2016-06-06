#pragma once
#include <exception>

class NiepoprawnaAlokacja :
	public std::exception
{
public:
	NiepoprawnaAlokacja(){}
	const char* what() const throw()
	{
		return "Podano zle parametry.";
	}

};


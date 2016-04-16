#include "Dyn_String.h"
#include <cstdlib>
#include <cstring>


Dyn_String::Dyn_String(const char* napis)
{
	this->tab = (char*)malloc(sizeof(char)*strlen(napis));
	if(this->tab!=NULL)
		strcpy(this->tab, napis);

}

Dyn_String::Dyn_String(const Dyn_String& kopia)
{
	this->tab = (char*)malloc(sizeof(char)*strlen(kopia.tab));

	if (this->tab != NULL)
		strcpy(tab, kopia.tab);

}

unsigned int Dyn_String::Size() const
{
	return strlen(tab);
}



const char* Dyn_String::Cstr() const
{
	return tab;
}

void Dyn_String::operator += (const char* napis) 
{
	unsigned int roztab = strlen(tab);
	unsigned int rozmiar = strlen(tab) + strlen(napis);
	tab = (char*)realloc(tab, rozmiar*sizeof(char));

	if (tab!=NULL)
	{
		tab[roztab] = '\0';
		strcat(tab, napis);
	}
}

void Dyn_String::operator ! ()
{
	unsigned int size = strlen(tab);
	for (unsigned int i = 0; i < size;i++)
	{
		if (tab[i] >= 97 && tab[i] <= 122)
		{
			tab[i] -= 32;
		}
		else if (tab[i] >= 65 && tab[i] <= 90)
		{
			tab[i] += 32;
		}
	}
}



Dyn_String::~Dyn_String()
{
}

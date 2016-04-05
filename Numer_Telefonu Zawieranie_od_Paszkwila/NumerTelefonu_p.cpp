#include "NumerTelefonu_p.h"



NumerTelefonu_p::NumerTelefonu_p(int kier, char* num, Type type)
{
	ZerujNumer(Numer, 10);
	Kierunkowy = kier;
	strcat(Numer, num);
	typ = type;
}

void NumerTelefonu_p::ZerujNumer(char* num, int i)
{
	for (int n = 0; n < i; n++)
	{
		Numer[n] = '/0';
	}
}

int NumerTelefonu_p::ZwrocKierunkowy()
{
	return Kierunkowy;
}

char* NumerTelefonu_p::ZwrocNumer()
{
	return this->Numer;
}

char* NumerTelefonu_p::ZwrocTyp()
{
	if (typ == KOMORKOWY)
		return "komorkowy";
	else if (typ == DOMOWY)
		return "domowy";
	else if (typ == SLUZBOWY)
		return "sluzbowy";
}



//char* NumerTelefonu_p::WypiszPelnyNumer(int kierunkowy_t, char* numer_t, Type typ_t)
//{
//	int jednosci = kierunkowy_t % 10;
//	int dziesiatki = ((kierunkowy_t % 100) - jednosci) / 10;
//
//	char kier[2];
//
//	char typtele[10];
//	ZerujNumer(typtele, 15);
//
//	char tab[30];
//	ZerujNumer(tab, 30);
//
//	kier[0] = jednosci + 48;
//	kier[1] = dziesiatki + 48;
//
//	if (typ_t == 0)
//		strcat(typtele, "Komorkowy");
//	else
//		if (typ_t == 1)
//			strcat(typtele, "Domowy");
//		else
//			if (typ_t == 0)
//				strcat(typtele, "Sluzbowy");
//
//	strcat(tab, typtele);
//	strcat(tab, kier);
//	strcat(tab, numer_t);
//
//	return tab;
//}

//
//void NumerTelefonu_p::ScalNumer(char* numer, char* kier)
//{
//	int jednosci = _kod1 % 10;
//	int dziesiatki = ((_kod1 % 100)-jednosci) / 10;
//	int setki = ((_kod1 % 1000)-dziesiatki-jednosci) / 100;
//
//	numer[0] = setki + 48;
//	numer[1] = dziesiatki + 48;
//	numer[2] = jednosci + 48;
//
//	jednosci = _kod2 % 10;
//	dziesiatki = ((_kod2 % 100) - jednosci) / 10;
//	setki = ((_kod2 % 1000) - dziesiatki - jednosci) / 100;
//
//	numer[3] = setki + 48;
//	numer[4] = dziesiatki + 48;
//	numer[5] = jednosci + 48;
//
//
//
//}


NumerTelefonu_p::~NumerTelefonu_p(void)
{
}

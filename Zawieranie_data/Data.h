#pragma once
class Data
{
	int Dzien;
	int Miesiac;
	int Rok;

public:

	char* PelnaData(int, int, int);
	void Zeruj(char*);
	Data();
	Data(int, int, int);

	int WypiszDzien() const;
	int WypiszMiesiac() const;
	int WypiszRok() const;

	void ZmienDate(int, int, int);

	
	~Data(void);
};


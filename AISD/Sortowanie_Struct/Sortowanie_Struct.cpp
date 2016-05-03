// Sortowanie_Struct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <malloc.h>
#include <conio.h>
FILE *plik;


enum Wybor
{
	SR_ROS=1,
	SR_MAL=2,
	MAX_ROS=3,
	MIN_MAL=4
};

struct point
{
	float x, y, z;
};

float max(float x, float y, float z)
{
	float max = x;
	if (max < y)
		max = y;
	else
		if (max < z)
			max = z;
	return max;
}

void SortujPrzezWybieranie(point *strukt, Wybor tryb)
{
	float x, y, z;

	for (int i = 0; i < 10; ++i)
	{
		int k = i;
		for (int j = i + 1; j < 10; ++j)
		{
			switch (tryb)
			{
			case 0: if ((strukt[i].x + strukt[i].y + strukt[i].z) / 3 < (strukt[j].x + strukt[j].y + strukt[j].z) / 3)
																														//((max(strukt[i].x, strukt[i].y, strukt[i].z) / 3) < (max(strukt[j].x, strukt[j].y, strukt[j].z) / 3))
				k = j;
				break;
			case 1: if ((strukt[i].x + strukt[i].y + strukt[i].z) / 3 > (strukt[j].x + strukt[j].y + strukt[j].z) / 3)
																														//((max(strukt[i].x, strukt[i].y, strukt[i].z) / 3) > (max(strukt[j].x, strukt[j].y, strukt[j].z) / 3))
				k = j;
				break;
			case 2: if ((max(strukt[i].x, strukt[i].y, strukt[i].z) / 3) > (max(strukt[j].x, strukt[j].y, strukt[j].z) / 3))
				k = j;
				break;
			case 3: if ((max(strukt[i].x, strukt[i].y, strukt[i].z) / 3) < (max(strukt[j].x, strukt[j].y, strukt[j].z) / 3))
				k = j;

			}
		}
	
		x = strukt[k].x;
		y = strukt[k].y;
		z = strukt[k].z;
		strukt[k].x = strukt[i].x;
		strukt[k].y = strukt[i].y;
		strukt[k].z = strukt[i].z;
		strukt[i].x = x;
		strukt[i].y = y;
		strukt[i].z = z;
	}

}

int main()
{
	point tab[10];
	FILE *file;
	bool repeat = false;
	int l = 0;
	if (file = fopen("liczby.txt", "r"))
	{
		for (int i = 0; i < 10; i++)
		{
			fscanf(file, "%f%f%f", &tab[i].x, &tab[i].y, &tab[i].z);
			l++;
		}
		for (int i = 0; i < 10; i++)
		{
			printf("%6.1f, %6.1f, %6.1f\n", tab[i].x, tab[i].y, tab[i].z);
		}
		Wybor n;
		printf("%d Wybierz typ sortowania:\n", l);
		printf("1. Wedlug sredniej arytmetycznej trojek liczb, rosnaco,\n");
		printf("2. Wedlug sredniej arytmetycznej trojek liczb, malejaco,\n");
		printf("3. Wedlug najwiekszej z kazdej trojki liczb, rosnaco,\n");
		printf("4. Wedlug najmniejszej z kazdej trojki liczb, malejaco\nWybor: ");
		do
		{
			scanf("%d", &n);
			switch (n)
			{
			case 1:
				printf("\nSortowanie wedlug sredniej arytmetycznej trojek liczb (rosnaco)\n");
				SortujPrzezWybieranie(tab, n);
				break;

			case 2:
				printf("\nSortowanie wedlug sredniej arytmetycznej trojek liczb (malejaco)\n");
				SortujPrzezWybieranie(tab, n);
				break;

			case 3:
				printf("\nSortowanie wedlug najwiekszej z kazdej trojki liczb (rosnaco)\n");
				SortujPrzezWybieranie(tab, n);
				break;

			case 4:
				printf("\nSortowanie wedlug najmniejszej z kazdej trojki liczb (malejaco)\nWybor: ");
				SortujPrzezWybieranie(tab, n);
				break;

			default:
				printf("Wybierz ponownie: ");
			}
		} while (!(n < 5 && n > 0));

		for (int i = 0; i < 10; i++)
		{
			printf("%6.2f, %6.2f, %6.2f\n", tab[i].x, tab[i].y, tab[i].z);
		}
	}
	else
		printf("Otwarcie pliku nie powiodlo sie. Nastapi wylaczenie programu.");
	_getch();
    return 0;
}


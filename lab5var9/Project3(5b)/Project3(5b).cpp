#include <iostream>
#include <stdio.h>

int main()
{
	//1 - гриб, 2-4 - гриба, 5-20 - грибов
	setlocale(LC_ALL, "rus");
	 unsigned int g;

	printf("Введите кол-во ваших грибов:  ");
	scanf_s("%d", &g);

	if ((g >= 11 && g <= 20) || (g >= 111 && g <= 120) || (g >= 1111 && g <= 1120))
	{
		printf("У меня %d грибов", g);

	}


	else if (g % 10 >= 5 || g % 10 == 0)
	{
		printf("У меня %d грибов", g);
	}


	else if (g % 10 == 2 || g % 10 == 3 || g % 10 == 4)
	{
		printf("У меня %d гриба", g);
	}


	else if (g % 10 == 1)
	{
		printf("У меня %d гриб", g);
	}
	
}

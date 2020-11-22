#include <iostream>
#include <stdio.h>
#include <math.h>

int main() {

	setlocale(LC_ALL, "ru");

	long n;                     // параметр ряда  
	double dbn, term, sum = 0;  // параметр ряда с плав. точкой  / значение члена ряда / значение суммы ряда
	short s1 = 1;               //  вспомогательная переменная 
	const double PT = 0.000001; // представление предела точности

	for (n = 0; ; n++, s1 *= -1) {

		dbn = n;                                    // Преобразовываем тип переменной
		term = s1 * (dbn + 1) / (pow(2, n - 1));    // Уравнение

		if (abs(term) >= PT)

			sum += term; //  Cумма членов ряда
		else {
			break;
		}

		if (n == 9)
			printf("Сумма 10 членов ряда: %.7lf\n", sum);

	}

	printf("Сумма полного ряда чисел: %.7lf\n", sum);
	/*Сумма 10 членов ряда : 0,8750000
	  Сумма полного ряда чисел : 0,8888884*/

}



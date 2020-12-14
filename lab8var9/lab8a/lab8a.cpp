#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	setlocale(LC_ALL, "ru");

	/*int const N = 10;*/
	int mass[10] = {0};
	int pls = 0, qst;
	int smk = 0, nsmk = 0, s1 = 1, s2 = 6;
	

	for (int i = 0; pls < 10; ++i) { 
		printf("Выберите себе место:\n");
		
		if (pls < 10 && smk < 6 || pls < 10 && nsmk < 10) {

			printf("\n\nВы курите?(1-Да,2-Нет)  ");
			scanf_s("%d", &qst);
			

			switch (qst) {
			case 1:
				if (smk == 5) {
					printf("Все места для курящих заняты!\n");
					break;
				}
				else {
					mass[i] = 1; pls++; smk++;
					printf("Вам забронированно место:  %d\n\n", s1);
					s1++;
					break;
				}
				
			case 2:
				if (nsmk == 5) {
					printf("Все места для не курящих заняты!\n");
					break;
				}
				else {
					mass[i+5] = 2; pls++; nsmk++;
					printf("Вам забронированно место:  %d\n\n", s2);
					s2++;
					break;
				}
			default: printf("Что-то пошло не так... Возможно вы ввели не то число?\n");
				break;
			}
		}	
	}
		if (pls == 10) {
			printf("\nАбсолютно все места заняты!\n\n");
		}
}

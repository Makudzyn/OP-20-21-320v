//Kunchenko 23.10.2020

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


int main()
{
    setlocale(LC_ALL, "rus");

    char title1[10] = "Office", title2[10] = "SmartSute", title3[12] = "StarOffice";
    char maker1[10] = "Microsoft", maker2[10] = "Lotus", maker3[10] = "Sun";
    short np1 = 4, np2 = 5, np3 = 4;
    int cost1 = 870, cost2 = 1020, cost3 = 9; 


    /*char title1[10], title2[10], title3[12], maker1[10], maker2[10], maker3[10];
    short np1, np2, np3; //Number of parts(Кол-во частей)
    int cost1, cost2, cost3; */

   /* //Первая строка
    printf("1.Введите наименование,производителя,кол-во частей и цену(через пробелы)>> ");
    scanf("%s %s %hi %d", title1, maker1, &np1, &cost1);

    //Вторая строка
    printf("2.Введите наименование,производителя,кол-во частей и цену(через пробелы)>> ");
    scanf("%s %s %hi %d", title2, maker2, &np2, &cost2);

    //Третья строка
    printf("3.Введите наименование,производителя,кол-во частей и цену(через пробелы)>> ");
    scanf("%s %s %hi %d", title3, maker3, &np3, &cost3);
    printf("\n"); */

    //Таблица
    printf("|-------------------------------------------------------------|\n");
    printf("|                        Офисные пакеты                       |\n");
    printf("|-------------------------------------------------------------|\n");
    printf("| Наименование | Производитель | Кол-во сост.частей | Цена($) |\n");
    //Введенные данные
    printf("|--------------|---------------|--------------------|---------|\n");
    printf("|%13s | %-13s | %-18hi | %-7d |\n", title1, maker1, np1, cost1);
    printf("|--------------|---------------|--------------------|---------|\n");
    printf("|%-13s | %-13s | %-18hi | %-7d |\n", title2, maker2, np2, cost2);
    printf("|--------------|---------------|--------------------|---------|\n");
    printf("|%-13s | %-13s | %-18hi | %-7d |\n", title3, maker3, np3, cost3);
    printf("|-------------------------------------------------------------|\n");
    //Некоторые причемания
    printf("|  Примечание: возможно бесплатно получить продукт StarOffice |\n");
    printf("|  через Internet                                             |\n");
    printf("|-------------------------------------------------------------|\n");


}
#include <iostream>
#include <math.h>
#include <stdio.h>

int main() {

    short n, h; //Кол-во циклов, 
    double x, y;  

    printf("|   x   |      y     |\n");
    printf("|-------|------------|\n");


    for (n = 0; n < 5; n++) {
        
        for (x = 0; x < 4; x += 0.25) {

            // 1-й отрезок 
            if ( x <= 2) y = 2 - x;

            // 2-й отрезок 
            else if ( x > 2) y = 2 - sqrt(4 - (x - 2) * (x - 2)); 
            
            h = (y * 10)+1; 
            /*if (y - 1 - h * 10 > 0.5) h++;*/ /*double round(h);*/

            printf("| %5.2lf | %10.7lf |", x + n * 4, y); //Выведение данных в таблицу

            //Построение рисунка графика
            for (; h > 0; h--) {
                printf("-");
            }
            printf(".\n");
        }  
 
    } 

}



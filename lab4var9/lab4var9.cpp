#include <stdio.h>
#include <Windows.h>
#include <iostream>


int main()
{
    setlocale(LC_ALL, "ru");

    unsigned int channelForm = 0;                   // формат команды канала
    char o, c, d;                                  // код операции O и признаки цепочки С и D
    unsigned char bytes;                          // количество байтов для передачи N

    printf("Программа упаковки\n");

    printf("\nВведите код операции (0 - 31) >> ");                    scanf_s("%hhd", &o);
    
    printf("\nПризнак цепочки команд (0 - 1) >> ");                   scanf_s("%hhd", &c);
    
    printf("\nВведите признак цепочки данных (0 - 1) >> ");           scanf_s("%hhd", &d);
    
    printf("\nВведите количество байтов для передачи (0 - 255) >> "); scanf_s("%hhd", &bytes);
    
    
    channelForm |= ((unsigned char)o & 0x1F) << 11;  //Упаковывание кода
    channelForm |= ((unsigned char)c & 1) << 10;
    channelForm |= ((unsigned char)d & 1) << 9;
    channelForm |= bytes & 0xFF;

    /* вывод результата */
    printf("\nУпакованная команда канала: %4x \n", channelForm);

}
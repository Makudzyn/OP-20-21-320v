#include <stdio.h>
#include <Windows.h>
#include <iostream>


int main()
{
    setlocale(LC_ALL, "ru");

    unsigned int channelForm = 0;                   // формат команды канала
    char o, c, d;                                  // код операции O и признаки цепочки С и D
    unsigned char bytes;                          // количество байтов для передачи N

    printf("Формат команды канала (16cc от 0 до 0xFFFF) >>"); scanf_s("%x", &channelForm);
    
    o = (channelForm >> 11) & 0x1F;
    c = (channelForm >> 10) & 1;
    d = (channelForm >> 9) & 1;
    bytes = channelForm & 0xFF;

    printf("Код операции >> %d\n", o);
    printf("Признак цепочки команд >> %d\n", c);
    printf("Признак цепочки данных >> %d\n", d);
    printf("Количество байтов для передачи >> %d\n", bytes);
}

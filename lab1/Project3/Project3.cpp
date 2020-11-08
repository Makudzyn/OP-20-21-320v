//10.10.2020 Kunchenko

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

int main()
{
    int z, x, c, res;

    printf("Insert number=");
    scanf_s("%d", &z);
    x = z * z;
    c = x * x;
    res = c * c;
    printf("Result= %d", res);
}
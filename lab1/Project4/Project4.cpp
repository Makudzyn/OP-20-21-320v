//10.10.2020 Kunchenko

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
	printf("first task");

	int s1 = 19, s2 = 81;

	printf("default: %d, %d \n", s1, s2);

	s1 = s1 + s2;
	s2 = s1 - s2;
	s1 = s1 - s2;

	printf("changed in: %d, %d \n", s1, s2);

	printf("second task");

	int s3 = 68, s4 = 32, s5;


	printf("default: %d, %d \n", s3, s4);

	s5 = s3;
	s3 = s4;
	s4 = s5;

	printf("changed in: %d, %d ", s3, s4);

}
#include <iostream>
#include <ctime>

int const N = 100;
void massCreation(int mass[N][N], int stlb, int str) {
	srand(time(0));

	for (int i = 0; i < stlb ; i++){
		for (int j = 0; j < str; j++){
			mass[i][j] = rand() % 10 - 3;
			printf("%3d", mass[i][j]);
		}
		printf("\n");
	}
}
int positiveElements(int mass[N][N], int str, int stlb, int i, int allstr) {
	int k = 0, tmpMassForK[N];
	if (allstr == 0) {
	if (i < 0) {
		printf("\nВы ввели число которое меньше 0 , поэтому подсчет будет произведен для первой строки\n");
		i = 0;
	}
	if (i > stlb) {
		printf("\nВы ввели число которое больше кол-ва строк, поэтому подсчет будет произведен для последней строки\n");
		i = stlb - 1;
	}
	for (int j = 0; j < str; j++) {
		if (mass[i][j] >= 0) {
			k++;
		}
	}
	return k;
    }
	else if(allstr == 1){
		for (int i = 0; i < stlb; i++){
			tmpMassForK[i] = k;
			return printf("\nДля %d строки кол-во положительных",tmpMassForK[i]);
			for (int j = 0; j < str; j++){
				if (mass[i][j] >= 0) {
					k++;
				}
			}
		}
	
	}
}
int main(){
	setlocale(LC_ALL, "ru");
	int a1, a2, kst = 0, qst=0, allstr = 0;
	int mass[N][N] = { 0 };
	printf("Задайте размерность двумерного массива\n");
	printf("\nРазмер столбца >>  "); scanf_s("%d", &a1);
	printf("\nРазмер строки  >>  "); scanf_s("%d", &a2);
	massCreation(mass,a1,a2);
	printf("Если посчитать для определенной строки, напишите - 1, а если для всех - 0 >>  "); scanf_s("%d", &qst);

	if (qst == 1){
		printf("В какой строке хотите посчитать кол-во положительных элементов(0 - %d) >> ", a1 - 1); scanf_s("%d", &kst);
		printf("\nПоложительных элементов в этой строке: %d\n", positiveElements(mass, a1, a2, kst, allstr));
	}
	else if (qst == 0){
		allstr++;
		printf("\nПоложительных во всех строках: %d\n", positiveElements(mass, a1, a2, kst, allstr));
	}



}


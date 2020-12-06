#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main(void) {

	int	const N = 9;
	int mass[N][N] = { 0 };
	int line = N - 1, row = 0;

	for (int k = 1; k <= N * N; k++) {                // 8 0 | 8 1 | 7 0 | 8 2 | 7 1 | 6 0 | 8 3 | 7 2 | 6 1 | 5 0 |

		mass[line][row] = k;
		int lineTmp = line, rowTmp = row;

		if (line != 0 && row != 0) {                  //Проверка дохождения до границы
			line--; row--;
		}
		else if (line == 0 && row == 0) {             //Переход через середину, случай попадания в (0,0)
			line = N - 2;
			row = N - 1;
		}
		else if (row == 0) {                          //Переход столбцов
			line = N - 1;
			row = N - lineTmp;
		}
		else if (line == 0) {                         //Переход строк
			line = N - 2 - rowTmp;
			row = N - 1;
		}
	}

	for (int i = 0; i < N; i++) {                    //Вывод массива
		for (int j = 0; j < N; j++) {
			printf("%2d ", mass[i][j]);
		}
		printf("\n\n");
	}
}
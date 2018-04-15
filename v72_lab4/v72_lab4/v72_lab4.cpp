// v72_lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define M 4

int main()
{
	int Z[M][M] = { {5,12,8,29},{6,1,70,7},{7,2,12,96},{14,18,24,6} };
	int i, j;

	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++)
			printf("%3d", Z[i][j]);
		printf("\n");
	}
	printf("\n");

	int max = Z[0][0];
	for (i = 0; i < M - 1; i++) {
		for (j = 0; j < M - i - 1; j++) {
			if (Z[i][j] > max)
				max = Z[i][j];
		}
	}

	int min = Z[M - 1][M - 1];
	for (i = 0; i < M - 1; i++) {
		for (j = M - i - 1; j < M; j++) {
			if (Z[i][j] > min)
				min = Z[i][j];
		}
	}


	if (min / 2 > max) {

		for (i = 0; i < M; i++)
		{
			for (j = 0; j < M - i - 1; j++)
			{
				int tmp = Z[i][j];
				Z[i][j] = Z[M - i - 1][M - j - 1];
				Z[M - i - 1][M - j - 1] = tmp;
			}
		}

	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++)
			printf("%3d", Z[i][j]);
		printf("\n");
	}
	getchar();
	return 0;
}


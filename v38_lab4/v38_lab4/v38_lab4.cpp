// v38_lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define M 4
#define N 4

int main()
{
	int Z[M][N] = { { 3,9,2,7 },{ 1,4,5,5 },{ 8,7,4,1 },{ 1,11,2,7 } };
	int i, j, l, max, k, temp;

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			printf("%3d", Z[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < M; i++) {
		max = Z[i][0];
		for (j = 0; j < N; j++) {
			if (max < Z[i][j]) {
				max = Z[i][j];
			}
		}
		k = 0;
		for (j = 0; j < N; j++) {
			if (max == Z[i][j]) k = k + 1;
		}

		if (k == 1) {
			for (j = 0; j < max; j++)
			{
				temp = Z[i][0];
				for (l = 0; l < N - 1; l++)
					Z[i][l] = Z[i][l + 1];
				Z[i][N - 1] = temp;
			}
		}
		else {
			for (j = 0; j < max; j++) {
				temp = Z[i][N - 1];
				for (l = N - 1; l > 0; --l)
					Z[i][l] = Z[i][l - 1];
				Z[i][0] = temp;
			}
		}
	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			printf("%3d", Z[i][j]);
		}
		printf("\n");
	}

	getchar();
	return 0;
}


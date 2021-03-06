// v9_lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define M 4
#define N 4

int main()
{
	int E[M][N] = { { 7,5,3,2 },{ 5,9,6,1 },{ 1,0,2,9 },{ 3,4,2,3 } };
	int i, j, k;
	int temp, max, min, nmax, nmin, count;

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
			printf("%3d", E[i][j]);
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < M; i++) {
		count = 0;

		for (j = 0; j < N; j++)
			if (E[i][j] != 0) count++;

		if (count == N) {
			max = min = E[i][0];
			nmax = nmin = 0;
			for (k = 0; k < N; k++) {
				if (max < E[i][k]) {
					max = E[i][k];
					nmax = k;
				}
				if (min >= E[i][k]) {
					min = E[i][k];
					nmin = k;
				}
			}


			if (nmax < nmin) {

				for (j = 0; j < nmin - nmax; j++)
					for (k = nmax + 1; k < nmin - j - 1; k++)
						if (E[i][k] > E[i][k + 1]) {
							temp = E[i][k];
							E[i][k] = E[i][k + 1];
							E[i][k + 1] = temp;
						}

			}
		}
	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
			printf("%3d", E[i][j]);
		printf("\n");
	}

	getchar();

	return 0;
}


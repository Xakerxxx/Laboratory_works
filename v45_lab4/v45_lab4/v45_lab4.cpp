// v45_lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define M 6
#define N 6

int main()
{
	int E[M][N] = { {1,0,3,3,2,2},{6,2,2,3,1,1},{4,1,8,4,8,2},{3,2,5,6,3,7},{2,3,1,4,7,7},{8,2,7,0,6,8} };
	int i, j, max, k, kmax, temp;

	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++)
			printf("%3d", E[i][j]);
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < M; i++) {
		kmax = 0;
		max = E[i][0];

		for (j = 0; j < N; j++) {
			if (max <= E[i][j]) {
				max = E[i][j];
				kmax = 1;
			}
		}
		for (j = 0; j < N; j++)
			if (max == E[i][j]) kmax += 1;

		if ((kmax - 1) > 1) {

			for (k = 1; k < N; k++)
				for (j = 0; j < N - k; j++) {
					if (E[i][j] < E[i][j + 1]) {
						temp = E[i][j];
						E[i][j] = E[i][j + 1];
						E[i][j + 1] = temp;
					}
				}
		}
	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++)
			printf("%3d", E[i][j]);
		printf("\n");
	}
	getchar();
	return 0;
}


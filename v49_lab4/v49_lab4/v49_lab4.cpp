// v49_lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define M 4
#define N 4

int main()
{
	int S[M][N] = { {2,3,0,4},{8,6,4,10},{7,4,2,1},{7,3,5,9} };
	int i, j, k, l, count, count1;

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
			printf("%3d", S[i][j]);
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < M; i++) {
		count = 0;
		count1 = 0;
		for (j = 0; j < N; j++) {
			if ((S[i][j] % 2) == 0)
				count++;
			if ((S[i][j] % 2) != 0)
				count1++;
		}
		if (count == N) {
			for (k = 0; k < N / 2; k++) {
				int tmp = S[i][k];
				S[i][k] = S[i][N - k - 1];
				S[i][N - k - 1] = tmp;
			}
		}
		if (count1 == N) {
			for (k = 0; k < (N - 1); k++) {
				for (l = k + 1; l < N; l++) {
					if (S[i][k] < S[i][l]) {
						int tmp = S[i][k];
						S[i][k] = S[i][l];
						S[i][l] = tmp;
					}
				}
			}
		}
	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
			printf("%3d", S[i][j]);
		printf("\n");
	}

	getchar();
    return 0;
}


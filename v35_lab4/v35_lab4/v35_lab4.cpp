// v35_lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "math.h"

#define N 4
#define M 4

int main()
{
	int D[M][N] = { { -1,7,10,21 },{ 3,4,-2,8 },{ 8,5,0,4 },{ -7,12,13,25 } };
	int i, j, k, tmp = 0, count = 0;

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			printf("%3d", D[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < M; i++) {
		for (j = 0; j < (N - 1); j++) {
			if (D[i][j] < D[i][j + 1]) {
				count++;
			}
			else {
				count = 0;
			}
		}
		if (count == (N - 1))
			tmp++;
		count = 0;
	}
	
	if (tmp % 2 == 0) {
		for (i = 0; i < M; i++) {
			for (j = 0; j < (N - 1); j++) {
				if (D[i][j] < D[i][j + 1]) {
					count++;
				}
				else {
					count = 0;
				}
				if (count == (N - 1)) {
					count = 0;
					for (k = 0; k <= (N - 1) / 2; k++) {
						tmp = D[i][k];
						D[i][k] = D[i][N - k - 1];
						D[i][N - k - 1] = tmp;
					}
				}
			}
			count = 0;
		}
	}
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			printf("%3d", D[i][j]);
		}
		printf("\n");
	}

	getchar();
	return 0;
}


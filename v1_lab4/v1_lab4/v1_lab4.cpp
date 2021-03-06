// v1_lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define M 6
#define N 6

int main()
{
	int D[M][N] = { { 1,0,3,7,2,2 },{ 6,2,2,3,1,1 },{ 9,1,6,4,8,2 },{ 3,2, 5,6,3,7 },{ 2,3,1,4 ,  0,7 },{ 8,2 , 7,0,6,8 } };
	int i, j, max, min, jmax, jmin, temp;

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
			printf("%d ", D[i][j]);
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < M; i++) {
		max = min = D[i][0];
		jmax = jmin = 0;
		for (j = 0; j < N; j++) {
			if (max < D[i][j]) {
				max = D[i][j];
				jmax = j;
			}
			if (min > D[i][j]) {
				min = D[i][j];
				jmin = j;
			}
		}
		if (jmin > jmax) {
			temp = D[i][jmin];
			D[i][jmin] = D[i][jmax];
			D[i][jmax] = temp;
		}
	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
			printf("%d ", D[i][j]);
		printf("\n");
	}

	getchar();
	return 0;
}


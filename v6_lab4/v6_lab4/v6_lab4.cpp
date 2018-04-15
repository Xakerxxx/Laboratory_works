// v6_lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define M 4
#define N 4

int main()
{
	int C[M][N] = { { 9,1,6,5 },{ 2,8,1,3 },{ 6,2,5,7 },{ 10,0,7,2 } };
	int S = 0, i, j, temp, m, k, l, x = 0;

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
			printf("%2d", C[i][j]);
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			S += C[i][j];

	S = S / (N*M);

	for (k = 0; k < N - 1 - x; k++)
	{
		x++;
		m = 0;
		for (l = 0; l < M; l++)
			if (C[k][l] > S)m += 1;

		if (m >(N / 2))
		{
			for (j = 0; j < M; j++)
			{
				for (i = k + 1; i<N; i++)
				{
					temp = C[i - 1][j];
					C[i - 1][j] = C[i][j];
					C[i][j] = temp;
				}
			}
		}
	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
			printf("%2d", C[i][j]);
		printf("\n");
	}

	getchar();
	return 0;
}


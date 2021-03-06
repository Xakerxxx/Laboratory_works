// v19_lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define N 4
#define M 4

int main()
{
	int MP[N][M] = { { 2,1,7,8 },{ 5,9,2,4 },{ 10,3,12,11 },{ 4,13,7,60 } };
	int min = MP[0][0];
	int max = MP[0][0];
	int i, j, k, s, tmp, count = 0;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)
			printf("%3d", MP[i][j]);
		printf("\n");
	}
	printf("\n");

	for (i = 0; i<N; i++)
	{
		for (j = 0; j<M; j++)
		{
			if (min > MP[i][j]) min = MP[i][j];
			if (max < MP[i][j]) max = MP[i][j];
		}
	}

	s = max - min;

	for (j = 0; j<(N - 1); j++)
	{
		count = 0;
		for (i = 0; i < M; i++)
		{
			if ((MP[j][i] != s) && (MP[j][i + 1] != s))
			{
				count++;
			}
		}
		if (count == N)
		{
			for (k = 0; k<N; k++)
			{
				tmp = MP[k][j];
				MP[k][j] = MP[k][j + 1];
				MP[k][j + 1] = tmp;
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)
			printf("%3d", MP[i][j]);
		printf("\n");
	}

	getchar();
	return 0;
}
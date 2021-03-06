// v16_lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define N 4 
#define M 4 

int main()
{
	int LU[N][M] = { { -1, -6, 3, 2 },{ 0,  -5, -2, 0 },{ 9, 12, 6, -3 },{ -4, 1, -2, -4 } };
	int i, j, k, tmp, sum = 0, count = 0, sh = 0;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			printf("%3d", LU[i][j]);
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < N - count; i++)
	{
		for (j = 0; j < M; j++)
		{
			sum += LU[i][j];
		}
		if (sum < 0)
		{
			for (j = i; j < N - 1; j++)
			{
				for (k = 0; k < M; k++)
				{
					tmp = LU[j][k];
					LU[j][k] = LU[j + 1][k];
					LU[j + 1][k] = tmp;
				}
			}
		}
		for (j = 0; j < M; j++)
		{
			sum += LU[i][j];
		}
		if (sum < 0)i--;
		count++;
		sum = 0;
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			printf("%3d", LU[i][j]);
		printf("\n");
	}
	printf("\n");

	for (i = N - 1, k = 0; k < count; i--, k++)
	{
		for (j = 0; j < M; j++)
		{
			if (LU[i][j] < 0)
			{
				LU[i][j] = 0;
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			printf("%3d", LU[i][j]);
		printf("\n");
	}

	getchar();
	return 0;
}

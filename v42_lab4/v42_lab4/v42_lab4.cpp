// v42_lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define M 4
#define N 4

int main()
{
	char f = true;
	int V[M][N] = { 4,8,20,10,-1,3,100,7,3,13,5,4,31,2,13,20 };
	int i, j, k, t, l, max, tmp;

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
			printf("%4d", V[i][j]);
		printf("\n");
	}
	printf("\n");

	max = V[0][M - 1];
	for (i = 0; i < M; i++)
	{
		for (j = M - i; j < N; j++)
		{
			if (max < V[i][j])
			{
				for (t = 0; t < M; t++)
				{
					for (k = 0; k < N - t - 1; k++)
					{
						if (V[i][j] == V[t][k])
						{
							f = false;
							k = N;
							t = M;
						}
						else
						{
							f = true;
							max = V[i][j];
						}
					}
				}
				if (f)
				{
					for (k = 0; k < M; k++)
					{
						for (t = 0; t < N; t++)
						{
							if (V[i][j] == V[k][t])
							{
								tmp = V[k][t];
								for (l = t; l > 0; l--)
									V[k][l] = V[k][l - 1];
								V[k][0] = tmp;
							}
						}
					}
					f = false;
				}
			}
		}
	}

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
			printf("%4d", V[i][j]);
		printf("\n");
	}

	getchar();
	return 0;
}


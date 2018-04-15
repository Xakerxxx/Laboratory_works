// v48_lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define N 4

int main()
{
	int i, j;
	int MS[N][N] = { {-1,4,-5,-3},{4,7,0,-1},{-1,2,-5,2},{-20,-9,7,2} };
	int s = 0, tmp;


	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			printf("%3d", MS[i][j]);
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (MS[i][j] < 0) s--;
			if (MS[j][i] > 0) s++;
		}
	}
	if (s == 0)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (MS[i][j] < 0)
				{
					for (int m = 0; m < N; m++)
					{
						for (int n = m + 1; n < N; n++)
						{
							if (MS[n][m] > 0)
							{
								tmp = MS[n][m];
								MS[n][m] = MS[i][j];
								MS[i][j] = tmp;
								m = N, n = N;
							}
						}
					}
				}
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			printf("%3d", MS[i][j]);
		printf("\n");
	}


	getchar();
	return 0;
}


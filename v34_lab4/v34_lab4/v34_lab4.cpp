// v34_lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define N 4
#define M 4

int main()
{
	int R[M][N] = { { 1,4,6,3 },{ 7,9,8,6 },{ 7,6,8,9 },{ 3,2,1,7 } };
	int i_s, i_f, i, j, k, max, y;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			printf("%3d", R[i][j]);
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (R[i][j] % 2 != 0)
			{
				i_s = j;
				for (k = i_s + 1; k < N; k++)
				{
					if (R[i][k] % 2 != 0)
					{
						i_f = k;
						k = N;
					}

				}
				j = N;
			}
		}
		if (i_s + 1 != i_f) {
			max = R[i][i_s + 1];
			for (j = i_s + 1; j < i_f; j++)
			{
				if (max < R[i][j])max = R[i][j];
			}
			for (j = i_s + 1, k = i_f; k < N; k++, j++)
			{
				R[i][j] = R[i][k];
			}
			if ((i_s - i_f) < 1) {
				y = 0;
				while (y < i_f - i_s - 1) {
					R[i][N - y - 1] = max;
					y++;
				}
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			printf("%3d", R[i][j]);
		printf("\n");
	}

	getchar();
	return 0;
}


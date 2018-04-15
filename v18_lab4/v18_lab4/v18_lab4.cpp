// v18_lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define N 4
#define M 4

int main()
{
	int AB[N][M] = { {18,24,28,20},{6,6,7,7},{20,24,25,18},{3,5,4,2} };
	int i, j, min, max, i_m, tmp_m, tmp_m1;

	for (i = 0; i < N; ++i) {
		for (j = 0; j < M; ++j)
			printf("%3d", AB[i][j]);
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < M; i++)
	{

		i_m = i;
		max = min = AB[i][0];

		for (j = 0; j < M; j++)
		{
			if (max < AB[i][j])
				max = AB[i][j];
			if (min > AB[i][j])
				min = AB[i][j];
		}
		tmp_m = max - min;
		for (j = i + 1; j < N; j++)
		{
			max = min = AB[j][0];
			for (int k = 0; k < M; k++)
			{
				if (max < AB[j][k])
					max = AB[j][k];
				if (min > AB[j][k])
					min = AB[j][k];
			}
			tmp_m1 = max - min;
			if (tmp_m1 < tmp_m)
			{
				i_m = j;
			}
		}
		if (i != i_m)
		{

			for (int c = 0; c < M; ++c)
			{
				int t = AB[i_m][c];
				AB[i_m][c] = AB[i][c];
				AB[i][c] = t;
			}
		}


	}

	for (i = 0; i < N; ++i) {
		for (j = 0; j < M; ++j)
			printf("%3d", AB[i][j]);
		printf("\n");
	}

	getchar();
	return 0;
}


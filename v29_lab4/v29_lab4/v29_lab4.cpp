// v29_lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define M 4
#define N 4

int main()
{
	int AB[N][M] = { {5,10,11,9},{7,8,9,2},{9,3,4,8},{3,1,5,6} };
	int i, j, min, max;
	int i_m, tmp_m, tmp_m1;

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
			if (tmp_m1 <= tmp_m)
			{
				i_m = j;
				tmp_m = tmp_m1;
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


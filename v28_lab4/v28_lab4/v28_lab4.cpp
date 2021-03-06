// v28_lab_4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define T 4

int main()
{
	int G[T][T] = { {9,7,10,6},{6,5,4,3},{0,2,3,8},{-4,1,7,2} };
	int s1 = 0, s2 = 0, tmp;

	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < T; j++)
			printf("%3d", G[i][j]);
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < T; i++)
	{
		for (int j = i + 1; j < T; j++)
		{
			s1 += G[i][j];
			s2 += G[j][i];
		}
	}
	if (s1 > s2)
	{
		for (int i = 0; i < T - 1; i++)
		{
			for (int j = T - i - 2; j >= 0; j--)
			{
				tmp = G[i][j];
				G[i][j] = G[T - j - 1][T - i - 1];
				G[T - j - 1][T - i - 1] = tmp;
			}
		}
	}
	else if (s2 > s1)
	{
		for (int i = 0; i < T; i++)
		{
			for (int j = i; j < T; j++)
			{
				tmp = G[i][j];
				G[i][j] = G[j][i];
				G[j][i] = tmp;
			}
		}
	}

	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < T; j++)
			printf("%3d", G[i][j]);
		printf("\n");
	}

	getchar();
	return 0;
}
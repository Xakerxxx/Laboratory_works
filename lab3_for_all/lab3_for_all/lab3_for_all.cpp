// lab3_for_all.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <math.h>

long double factorial(long double n)
{
	if (n <= 0) return 1;
	else return n * factorial(n - 1);
}

int main()
{
	double dblx, dblY, dblSN, dblSE, dbln, dblc;
	double dbla = -0.9;
	double dblb = 0.9;
	double dble = 0.0001;
	double dblh = (dblb - dbla) / 10.0;


	for (dblx = dbla; dblx <= dblb; dblx += dblh)
	{
		dblSN = 0;
		for (dbln = 0; dbln <= 40; dbln++)
		{
			dblc = pow(-1, dbln)*pow(dblx, dbln);
			dblSN += dblc;
		}
		dbln = 0;
		dblSE = 0;
		do
		{
			dblc = pow(-1, dbln)*pow(dblx, dbln);
			dblSE += dblc;
			dbln++;
		} while (fabs(dblc) > dble);

		dblY = 1 / (1 + dblx);

		printf("X=%9f SN=%9f SE=%9f Y=%9f\n", dblx, dblSN, dblSE, dblY);
	}

	getchar();
	return 0;
}


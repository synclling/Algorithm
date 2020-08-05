#include "FastestWay.h"
#include <iostream>

void fastest_way(int e1, int e2, int x1, int x2, int *a1, int *a2, int *t1, int *t2, int *f1, int *f2, int *L1, int *L2, int n, int &F, int &L)
{
	f1[1] = e1 + a1[1];
	f2[1] = e2 + a2[1];

	for (int i = 2; i <= n; ++i)
	{
		if (f1[i - 1] + a1[i] < f2[i - 1] + t2[i - 1] + a1[i])
		{
			f1[i] = f1[i - 1] + a1[i];
			L1[i] = 1;
		}
		else
		{
			f1[i] = f2[i - 1] + t2[i - 1] + a1[i];
			L1[i] = 2;
		}

		if (f2[i - 1] + a2[i] < f1[i - 1] + t1[i - 1] + a2[i])
		{
			f2[i] = f2[i - 1] + a2[i];
			L2[i] = 2;
		}
		else
		{
			f2[i] = f1[i - 1] + t1[i - 1] + a2[i];
			L2[i] = 1;
		}
	}

	if (f1[n] + x1 < f2[n] + x2)
	{
		F = f1[n] + x1;
		L = 1;
	}
	else
	{
		F = f2[n] + x2;
		L = 2;
	}
}

void print_stations(int *L1, int *L2, int n, int F, int L)
{
	std::cout << "the fast time is :" << F << std::endl;
	std::cout << "the station :" << n << " is on line :" << L << std::endl;

	int i = L;
	for (int j = n; j >= 2; --j)
	{
		if (i == 1)
		{
			i = L1[j];
		}
		else
		{
			i = L2[j];
		}

		std::cout << "the station :" << j - 1 << " is on line :" << i << std::endl;
	}
}
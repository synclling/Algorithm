#include "FastestWay.h"

void fastest_way(int e1, int e2, int x1, int x2, int *a1, int *a2, int *t1, int *t2, int *f1, int *f2, int *L1, int *L2, int n, int &L)
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
	}
}
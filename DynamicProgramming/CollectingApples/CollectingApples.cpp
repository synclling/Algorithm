#include "CollectingApples.h"
#include <malloc.h>

int apples_count(int **a, int **dp, int n, int m)
{
	int i, j;

	dp[0][0] = a[0][0];

	for (i = 1; i < n; ++i)
	{
		dp[0][i] = a[0][i - 1] + a[0][i];
	}

	for (j = 1; j < m; ++j)
	{
		
	}
}
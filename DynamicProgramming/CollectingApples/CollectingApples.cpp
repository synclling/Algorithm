#include "CollectingApples.h"
#include <malloc.h>

int apples_count(int **a, int **dp, int n, int m)
{
	int i, j;

	dp[0][0] = a[0][0];

	for (i = 1; i < n; ++i)
	{
		dp[0][i] = dp[0][i - 1] + a[0][i];
	}

	for (j = 1; j < m; ++j)
	{
		dp[j][0] = dp[j - 1][0] + a[j][0];
	}

	for (i = 1; i < n; ++i)
	{
		for (j = 1; j < m; ++j)
		{
			dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? (dp[i - 1][j] + a[i][j]) : (dp[i][j - 1] + a[i][j]);
		}
	}

	return dp[m - 1][n - 1];
}
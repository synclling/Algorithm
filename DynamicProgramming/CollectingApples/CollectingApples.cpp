#include "CollectingApples.h"

int n, m;	// n * m阶数
int a[20][20] = { 0 };
int dp[20][20] = { 0 };

void collecting_apples(int n, int m)
{
	dp[0][0] = a[0][0];

	int i, j;

	for (i = 1; i < n; ++i)
	{
		dp[i][0] = dp[i - 1][0] + a[i][0];
	}
	
	for (j = 1; j < m; ++j)
	{
		dp[0][j] = dp[0][j - 1] + a[0][j];
	}

	for (i = 1; i < n; ++i)
	{
		for (j = 1; j < m; ++j)
		{
			dp[i][j] = (dp[i][j - 1] > dp[i - 1][j]) ? (dp[i][j - 1] + a[i][j]) : (dp[i - 1][j] + a[i][j]);
		}
	}
}


// Recursively 
// start with: collecting_apples_recursively(0, 0);
void collecting_apples_recursively(int x, int y)
{
	dp[x][y] = a[x][y];

	int max = 0;
	
	if (x > 0 && max < dp[x - 1][y])
	{
		max = dp[x - 1][y];
	}
	if (y > 0 && max < dp[x][y - 1])
	{
		max = dp[x][y - 1];
	}

	dp[x][y] += max;

	if (x < n - 1)
	{
		collecting_apples_recursively(x + 1, y);
	}

	if (y < m - 1)
	{
		collecting_apples_recursively(x, y + 1);
	}
}
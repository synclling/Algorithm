#include "LCS.h"
#include <string.h>

int LCS(char *str1, char *str2, int **c, int **b)
{
	int m = strlen(str1);
	int n = strlen(str2);

	int i, j;

	for (i = 0; i <= m; ++i)
	{
		c[i][0] = 0;
	}

	for (j = 0; j <= n; ++j)
	{
		c[0][j] = 0;
	}

	for (i = 1; i <= m; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = EQUAL;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = UP;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = LEFT;
			}
		}
	}

	return c[m][n];
}
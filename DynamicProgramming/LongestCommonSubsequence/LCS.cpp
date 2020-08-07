#include "LCS.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include <stack>

int lcs_length(char *str1, char *str2, int **c, int **b)
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

void print_lcs_recursively(char *str1, int **b, int i, int j)
{
	if (i == 0 || j == 0)
		return;

	if (b[i][j] == EQUAL)
	{
		print_lcs(str1, b, i - 1, j - 1);
		printf("%c", str1[i - 1]);
	}
	else if (b[i][j] == UP)
	{
		print_lcs(str1, b, i - 1, j);
	}
	else
	{
		print_lcs(str1, b, i, j - 1);
	}
}

void print_lcs(char *str1, int **b, int i, int j)
{
	std::stack<char> s;

	while (i != 0 && j != 0)
	{
		if (b[i][j] == EQUAL)
		{
			s.push(str1[i - 1]);
			--i;
			--j;
		}
		else if (b[i][j] == UP)
		{
			--i;
		}
		else
		{
			--j;
		}
	}

	while (!s.empty())
	{
		printf("%c", s.top());
		s.pop();
	}
}

void lcs(char *str1, char *str2)
{
	int i, j;

	int m = strlen(str1);
	int n = strlen(str2);

	// 分配空间
	int **c = (int **)malloc(sizeof(int *) * (m + 1));
	int **b = (int **)malloc(sizeof(int *) * (m + 1));

	for (i = 0; i <= m; ++i)
	{
		c[i] = (int *)malloc(sizeof(int) * (n + 1));
		b[i] = (int *)malloc(sizeof(int) * (n + 1));
	}

	// 初始化为0
	for (i = 0; i <= m; ++i)
	{
		for (j = 0; j <= n; ++j)
		{
			c[i][j] = 0;
			b[i][j] = 0;
		}
	}

	int length = lcs_length(str1, str2, c, b);
	printf("The number of the longest-common-subsequence is %d\n", length);

	printf("The longest-common-subsequence is: ");
	print_lcs(str1, b, m, n);
	printf("\n");

	for (i = 0; i <= m; ++i)
	{
		free(c[i]);
		free(b[i]);
	}

	free(c);
	free(b);
}
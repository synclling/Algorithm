// main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "CollectingApples.h"
#include <iostream>

extern int n, m;
extern int a[20][20];
extern int dp[20][20];

int main()
{
	// {5, 8, 5, 7, 1, 8},
	// {1, 3, 2, 8, 7, 9},
	// {7, 8, 6, 6, 8, 7},
	// {9, 9, 8, 1, 6, 3},
	// {2, 4, 10, 2, 6, 2},
	// {5, 5, 2, 1, 8, 8}

	std::cout << "enter n, m: ";
	std::cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cin >> a[i][j];
		}
	}

#if 0
	collecting_apples(n, m);
#else
	collecting_apples_recursively2(n - 1, m - 1);
#endif

	std::cout << "dp:" << std::endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << dp[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "The max apples: " << dp[n - 1][m - 1] << std::endl;

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#include "HuffmanCode.h"
#include <malloc.h>

void Select(const HuffmanTree &HT, int n, int &s1, int &s2)
{
	s1 = 0;
	s2 = 0;

	unsigned int w1 = 0;
	unsigned int w2 = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (HT[i].parent == 0)
		{
			if (s1 == 0)
			{
				s1 = i;
				w1 = HT[i].weight;
				continue;
			}

			if (s2 == 0)
			{
				s2 = i;
				w2 = HT[i].weight;
				continue;
			}

			if (w1 > w2 && w1 > HT[i].weight)
			{
				s1 = i;
				w1 = HT[i].weight;
				continue;
			}

			if (w2 > w1 && w2 > HT[i].weight)
			{
				s2 = i;
				w2 = HT[i].weight;
				continue;
			}
		}
	}

	// 保证s1的权值小于s2的权值
	if (w1 > w2)
	{
		int temp = s1;
		s1 = s2;
		s2 = temp;
	}
}

void InitHuffmanTree(HuffmanTree &HT, unsigned int *w, int n, int m)
{
	int i;

	// 分配内存，0号单元未用
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HuffmanTreeNode));

	// 初始化1 ~ n
	for (i = 1; i <= n; ++i, ++w)
	{
		HT[i] = HuffmanTreeNode(*w, 0, 0, 0);
	}

	// 初始化n + 1 ~ m
	for (; i <= m; ++i)
	{
		HT[i] = HuffmanTreeNode(0, 0, 0, 0);
	}
}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, unsigned int *w, int n)
{
	if (n <= 1)	return;

	int i, s1, s2;
	int m = 2 * n - 1;
	
	// 初始化Huffman tree
	InitHuffmanTree(HT, w, n, m);

	// 构建Huffman tree
	for (i = n + 1; i <= m; ++i)
	{
		// 在HT[1...i - 1]选择parent为0且weight最小的两个结点，其序号为s1、s2
		Select(HT, i - 1, s1, s2);
		
		HT[s1].parent = i;
		HT[s2].parent = i;

		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}


	// ---从叶子结点到根逆向求每个字符的Huffman编码
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));

	char *code = (char *)malloc(n * sizeof(char));
	code[n - 1] = '\0';

	for (i = 1; i <= n; ++i)
	{
		int start = n - 1;
		for (int c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
		{
			code[--start] = (c == HT[f].lchild) ? '0' : '1';
		}

		HC[i] = (char *)malloc((n - start) * sizeof(char));
		
		for (int j = 0; j < (n - start); ++j)
			HC[i][j] = code[start + j];
	}

	free(code);
}

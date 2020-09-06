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

	// ��֤s1��ȨֵС��s2��Ȩֵ
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

	// �����ڴ棬0�ŵ�Ԫδ��
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HuffmanTreeNode));

	// ��ʼ��1 ~ n
	for (i = 1; i <= n; ++i, ++w)
	{
		HT[i] = HuffmanTreeNode(*w, 0, 0, 0);
	}

	// ��ʼ��n + 1 ~ m
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
	
	// ��ʼ��Huffman tree
	InitHuffmanTree(HT, w, n, m);

	// ����Huffman tree
	for (i = n + 1; i <= m; ++i)
	{
		// ��HT[1...i - 1]ѡ��parentΪ0��weight��С��������㣬�����Ϊs1��s2
		Select(HT, i - 1, s1, s2);
		
		HT[s1].parent = i;
		HT[s2].parent = i;

		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}

#if 0
	// ---��Ҷ�ӽ�㵽��������ÿ���ַ���Huffman����
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char *)); // 0�ŵ�Ԫδ��

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
#else
	// ---�Ӹ���������������Huffman tree��ÿ���ַ���Huffman����
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char *)); // 0�ŵ�Ԫδ��

	char *code = (char *)malloc(n * sizeof(char));
	int cdlen = 0;

	unsigned int p = m; // ָ������

	for (i = 1; i <= m; ++i)
		HT[i].weight = 0; // ����Huffman treeʱ�������״̬��־

	while (p != 0)
	{
		if (HT[p].weight == 0) // ����
		{
			HT[p].weight = 1;

			if (HT[p].lchild != 0) // �����ӽ��
			{
				p = HT[p].lchild;
				code[cdlen++] = '0';
			}
			else // Ҷ�ӽ��
			{
				HC[p] = (char *)malloc((cdlen + 1) * sizeof(char));

				code[cdlen] = '\0';
				for (int j = 0; j <= cdlen; ++j)
					HC[p][j] = code[j];
			}
		}
		else if (HT[p].weight == 1) // ����
		{
			HT[p].weight = 2;

			if (HT[p].rchild != 0) // ���Һ��ӽ��
			{
				p = HT[p].rchild;
				code[cdlen++] = '1';
			}
		}
		else // HT[p].weight == 2������
		{
			HT[p].weight = 0;
			p = HT[p].parent; // �˻ظ���㣬���볤�ȼ�1
			--cdlen;
		}
	}

	free(code);
#endif
}

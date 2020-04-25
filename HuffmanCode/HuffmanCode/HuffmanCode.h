#pragma once

#define UINTMAX 65535

typedef struct HuffmanTreeNode
{
	unsigned int weight;
	unsigned int parent, lchild, rchild;
} HTNode, *HuffmanTree;

typedef char** HuffmanCode;

/*
 *	@brief	����Huffman��HT�������n���ַ���Huffman����
 *	@param	[out]HT		Huffman��
 *	@param	[out]HC		Huffman����
 *	@param	[in]w		���n���ַ���Ȩֵ����
 *	@param	[in]n		n���ַ�
 */
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int* w, int n);
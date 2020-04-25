#pragma once

#define UINTMAX 65535

typedef struct HuffmanTreeNode
{
	unsigned int weight;
	unsigned int parent, lchild, rchild;
} HTNode, *HuffmanTree;

typedef char** HuffmanCode;

/*
 *	@brief	构造Huffman树HT，并求出n个字符的Huffman编码
 *	@param	[out]HT		Huffman树
 *	@param	[out]HC		Huffman编码
 *	@param	[in]w		存放n个字符的权值数组
 *	@param	[in]n		n个字符
 */
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int* w, int n);
#pragma once

//-----Huffman编码-----

// 设计长短不等的编码，则必须是任意一个字符的编码都不是其他字符的编码的前缀，这种编码称为前缀编码

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
 *	@param	[in]w		w存放n个字符的权值(均大于0)
 *	@param	[in]n		n个字符
 */
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n);
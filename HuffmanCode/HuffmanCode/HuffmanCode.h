#pragma once

//-----Huffman����-----

// ��Ƴ��̲��ȵı��룬�����������һ���ַ��ı��붼���������ַ��ı����ǰ׺�����ֱ����Ϊǰ׺����

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
 *	@param	[in]w		w���n���ַ���Ȩֵ(������0)
 *	@param	[in]n		n���ַ�
 */
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n);
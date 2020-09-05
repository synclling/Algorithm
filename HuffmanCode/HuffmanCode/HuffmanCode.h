#pragma once

//-----Huffman����-----

// ��Ƴ��̲��ȵı��룬�����������һ���ַ��ı��붼���������ַ��ı����ǰ׺�����ֱ����Ϊǰ׺����

typedef struct HuffmanTreeNode
{
	unsigned int weight;
	unsigned int parent, lchild, rchild;
	HuffmanTreeNode(unsigned int w, unsigned int p, unsigned int l, unsigned int r) : weight(w), parent(p), lchild(l), rchild(r) {}
} HuffmanTreeNode, *HuffmanTree;

typedef char** HuffmanCode;

/*
 *	@brief	����Huffman��HT�������n���ַ���Huffman����
 *	@param	[out]HT		Huffman��
 *	@param	[out]HC		Huffman����
 *	@param	[in]w		w���n���ַ���Ȩֵ(������0)
 *	@param	[in]n		n���ַ�
 */
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, unsigned int *w, int n);
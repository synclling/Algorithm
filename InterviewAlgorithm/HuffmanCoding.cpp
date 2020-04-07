#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define UINT_MAX 65535

typedef struct {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
} HTNode, *HuffmanTree;

typedef char ** HuffmanCode;	//��̬��������洢�շ������� 

int min_weight(HuffmanTree &HT, int n){
	int i, index;
	unsigned int min = UINT_MAX;
	for(i = 1; i <= n; ++i)
		if(HT[i].parent == 0 && HT[i].weight < min){
			min = HT[i].weight;
			index = i;
		}
	HT[index].parent = 1;	//��ѡ�еĽڵ��˫�׸�ֵ1�������ظ����� 
	return index;
	
}

void select(HuffmanTree &HT, int n, int &s1, int &s2){
	s1 = min_weight(HT, n);
	s2 = min_weight(HT, n);
} 

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n){
	if(n <= 1) return;
	int i, m;
	int s1, s2;
	int start, c, f;
	HuffmanTree p;
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));	//0�ŵ�Ԫδʹ�� 
	if(!HT){
		printf("HuffmanTree malloc faild!\n");
		exit(-2);
	}
	
	//��ʼ��
	for(p = HT + 1, i = 1; i <= n; ++i, ++p, ++w){	//1 ~ n��Ԫ  
		p->weight = *w;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	for(; i <= m; ++i, ++p){	//n + 1 ~ m��Ԫ 
		p->weight = 0;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	
	//���շ����� 
	for(i = n + 1; i <= m; ++i){
		select(HT, i - 1, s1, s2);
		HT[s1].parent = i;	HT[s2].parent = i;
		HT[i].lchild = s1;	HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	
	//-----��Ҷ�ӵ���������ÿ���ַ��ĺշ�������-----
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
	if(!HC){
		printf("HuffmanCode malloc faild!\n");
		exit(-2);
	}
	char *code = (char *)malloc(n * sizeof(char));
	if(!code){
		printf("code malloc faild!\n");
		exit(-2);
	}
	code[n - 1] = '\0';
	for(i = 1; i <= n; ++i){
		start = n - 1;
		for(c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
			if(HT[f].lchild == c)	code[--start] = '0';
			else	code[--start] = '1';
		HC[i] = (char *)malloc((n - start) * sizeof(char));
		strcpy(HC[i], &code[start]);
	}
	free(code);
}

int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int w[4] = {7, 5, 2, 4};
	HuffmanCoding(HT, HC, w, 4);
	for(int i = 1; i <= 4; ++i)
		printf("HC[%d]: %s\n", i, HC[i]);
	return 0;
}

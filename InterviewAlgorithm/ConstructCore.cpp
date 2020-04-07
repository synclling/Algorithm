#include<stdio.h>
#include<malloc.h>

typedef struct BiNode{
	int data;
	struct BiNode *lchild;
	struct BiNode *rchild;
} BiNode;

BiNode *ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder);

BiNode *Construct(int Preorder[], int Inorder[], int length){
	if(Preorder == NULL || Inorder == NULL || length <= 0)
		return NULL;
	return ConstructCore(Preorder, Preorder + length - 1, Inorder, Inorder + length - 1);
}

BiNode *ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder){
	//ǰ��������еĵ�һ�����־��Ǹ��ڵ��ֵ  
	int rootvalue = startPreorder[0];
	BiNode *root = (BiNode *)malloc(sizeof(BiNode));
	root->data = rootvalue;
	root->lchild = root->rchild = NULL;
	
	if(startPreorder == endPreorder){ //�ݹ��������  
		if(startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else{
			printf("Invalid Input0!\n");
			exit(-2);
		}
	}
	
	//������������ҵ����ڵ��ֵ 
	int *rootInorder = startInorder;
	while(rootInorder <= endInorder && *rootInorder != rootvalue)
		++rootInorder;
	
	if(rootInorder > endInorder){//��������в����ڸ��ڵ� 
		printf("Invalid Input1\n");
		exit(-2); 
	}
	
	int leftLength = rootInorder - startInorder;
	int *leftPreorderEnd = startPreorder + leftLength;
	
	if(leftLength > 0){
		root->lchild = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	
	if(leftLength < endPreorder - startPreorder){
		root->rchild = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}
	
	return root; 
}


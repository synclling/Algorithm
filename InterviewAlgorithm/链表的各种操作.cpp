#include<stdio.h>
#include<stdlib.h>

typedef struct LNode {
	int data;
	struct LNode *next;
} LNode;


LNode *ReverseList(LNode *head){	//反转链表 
	LNode *reverseHead = NULL;
	LNode *pNode = head;
	LNode *pPrev = NULL;
	while(pNode){
		LNode *pNext = pNode->next;
		if(!pNext)
			reverseHead = pNode;
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return reverseHead;
}

LNode *Merge(LNode *head1, LNode *head2){	//合并两个链表 
	if(!head1)	return head2;
	if(!head2)	return head1;
	
	LNode *Mergehead = NULL;
	
	if(head1->data <= head2->data){
		Mergehead = head1;
		Mergehead->next = Merge(head1->next, head2);
	}else{
		Mergehead = head2;
		Mergehead->next = Merge(head1, head2->next);
	}
	return Mergehead;
}

LNode *FindkthToTail(LNode *head, unsigned int k){	//查找链表中倒数第K个节点 
	if(!head || k == 0)
		return NULL;
	LNode *Ahead = head;
	LNode *Behild = NULL;
	
	for(unsigned int i = 0; i < k - 1; ++i){
		if(Ahead->next)
			Ahead = Ahead->next;
		else return NULL;
	}
	
	Behild = head;
	while(Ahead->next){
		Ahead = Ahead->next;
		Behild = Behild->next;
	}
	return Behild;
} 


void PrintListReversingly(LNode *head){	//从尾到头打印链表，递归 
	if(head){
		if(head->next)
			PrintListReversingly(head->next);
		printf("%d ", head->data);
	}
} //warnning:当链表很长时，有可能导致函数调用栈溢出，存在安全性问题 

void RemoveNode(LNode *head, int value){
	if(head == NULL)	return;
	LNode *DeleteNode =  NULL;
	if(head->data == value){
		DeleteNode = head;
		head = head->next;
	}else{
		LNode *pNode = head;
		while(pNode->next != NULL && pNode->next->data != value)
			pNode = pNode->next;
		if(pNode->next != NULL && pNode->next->data== value){
			DeleteNode = pNode->next;
			pNode->next = pNode->next->next;
		}
	}
	if(DeleteNode != NULL){
		free(DeleteNode);
		DeleteNode = NULL;
	}
}
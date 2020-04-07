#include<stdio.h>
#include<string.h>

typedef struct _Node{
	int data;
	struct _Node *next;
} Node;

typedef struct _Hash_Table{
	Node *value[10];
} Hash_Table;


Hash_Table *create()
{
	Hash_Table *pHash = (Hash_Table *)malloc(sizeof(Hash_Table));
	memset(pHash, 0, sizeof(Hash_Table));
	return pHash;
}

Node *find_data_in_hash(Hash_Table *pHash, int data)
{
	Node *pNode;
	if(pHash == NULL)
		return NULL;
	if((pNode = pHash->value[data % 10]) == NULL)
		return NULL;
	 while(pNode){
 		if(data == pNode->data)
 			return pNode;
		pNode = pNode->next;
 	}
 	
	return NULL;
} 

bool insert_data_into_hash(Hash_Table *pHash, int data)
{
	Node *pNode;
	if(pHash == NULL)
		return false;
	if(pHash->value[data % 10] == NULL){
		pNode = (Node *)malloc(sizeof(Node));
		memset(pNode, 0, sizeof(Node));
		pNode->data = data;
		pHash->value[data % 10] = pNode;
		return true;
	}
	
	if(find_data_in_hash(pHash, data) != NULL)
		return false;
	pNode = pHash->value[data % 10];
	while(pNode->next != NULL)
		pNode = pNode->next;
	
	pNode->next = (Node *)malloc(sizeof(Node));
	memset(pNode->next, 0, sizeof(Node));
	pNode->next->data = data;
	return true; 
}

bool delete_data_from_hash(Hash_Table *pHash, int data)
{
	Node *phead, *pNode;
	if(pHash == NULL || pHash->value[data % 10] == NULL)
		return false;
	if((pNode = find_data_in_hash(pHash, data)) == NULL)
		return false;
	
}
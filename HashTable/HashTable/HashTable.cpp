#include "HashTable.h"
#include <malloc.h>
#include <string.h>

HashTable* CreateHashTable()
{
	HashTable *hashtable = (HashTable *)malloc(sizeof(HashTable));
	memset(hashtable, 0, sizeof(HashTable));

	return hashtable;
}

int Hash(DataType data)
{
	return data % 10;
}

Node *Search(const HashTable *hashtable, DataType data)
{
	if (hashtable == NULL)
		return NULL;

	Node* p = hashtable->value[Hash(data)];
	if (p == NULL)
		return NULL;

	while (p != NULL)
	{
		if (p->data == data)
			return p;
		p = p->next;
	}

	return NULL;
}

int Insert(HashTable *hashtable, DataType data)
{

}

int Delete(HashTable *hashtable, DataType data)
{

}
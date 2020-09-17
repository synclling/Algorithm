#pragma once

#define HASH_TABLE_LENGTH 128	

typedef int DataType;

typedef struct Node
{
	DataType	data;
	struct Node	*next;
} Node, *NodePtr;

typedef struct HashTable
{
	NodePtr value[HASH_TABLE_LENGTH];
} HashTable;


HashTable* CreateHashTable();

int Hash(DataType data);

Node *Search(const HashTable *hashtable, DataType data);

int Insert(HashTable *hashtable, DataType data);

int Delete(HashTable *hashtable, DataType data);
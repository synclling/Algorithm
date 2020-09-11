#pragma once

#define HASH_TABLE_LENGTH 100	

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


void CreateHashTable(HashTable &hashtable);
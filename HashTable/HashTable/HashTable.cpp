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

int Divide(int dividend, int divisor)
{
	long long int y = (long long int)dividend;
	long long int x = (long long int)divisor;

	if (y < 0) y = 0 - y;
	if (x < 0) x = 0 - x;

	long long int tmp, one = -1, res = 0;
	int restmp;

	while (y >= x)
	{
		restmp = 0;
		tmp = x;
		while (y >= tmp)
		{
			tmp = tmp << 1;
			restmp++;
		}
		restmp--;
		y -= (x << restmp);
		res += (one << restmp);
	}

	if ((dividend > 0) ^ (divisor > 0))
		res = 0 - res;

	if (res > 2 ^ 32 - 1 || res < -2 ^ 32)
		res = 2 ^ 32 - 1;

	return res;
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
#include "pch.h"
#include "B-Tree.h"

int Search(BTNode* p, KeyType k)
{
	int i = 1;
	for (; i <= p->keynum && k >= p->key[i]; ++i); // 使得i:p->key[i] <= k < p->key[i + 1]
	return i - 1;
}

Result SearchBTree(BTNode* T, KeyType k)
{
	Result res;

	BTNode* p = T;
	BTNode* q = nullptr;

	int i = 0;
	bool found = false;

	while (p != nullptr && !found)
	{
		i = Search(p, k);
		if (i > 0 && k == p->key[i])
		{
			found = true;
		}
		else
		{
			q = p;
			p = p->ptr[i];
		}
	}

	if (found)
	{
		res.pt = p;
		res.i = i;
		res.tag = 1;
	}
	else
	{
		res.pt = q;
		res.i = i;
		res.tag = 0;
	}

	return res;
}

void InsertBTNode(BTNode* &p, int i, int k, BTNode* q)
{
	int j;
	for (j = p->keynum; j > i; --j)
	{
		p->key[j + 1] = p->key[j];
		p->ptr[j + 1] = p->ptr[j];
	}

	p->key[i + 1] = k;
	p->ptr[i + 1] = q;

	if (q != nullptr)
	{
		q->parent = p;
	}

	++p->keynum;
}

void SplitBTNode(BTNode* &p, BTNode* &q)
{
	int i;
	int s = (m + 1) / 2;
	q = new BTNode();

	q->ptr[0] = p->ptr[s];
	for (i = s + 1; i <= m; ++i)
	{
		q->key[i - s] = p->key[i];
		q->ptr[i - s] = p->ptr[i];
	}

	q->keynum = p->keynum - s;
	q->parent = p->parent;
	for (i = 0; i <= p->keynum - s; ++i)
	{
		if (q->ptr[i] != nullptr)
		{
			q->ptr[i]->parent = q;
		}
	}

	p->keynum = s - 1;
}

/*
void InsertBTree(BTree &t,int i,KeyType k,BTNode *p){
	BTNode *q;
	int finish_tag,newroot_tag,s;                   //设定需要新结点标志和插入完成标志
	KeyType x;
	if(p==NULL)                                     //t是空树
		NewRoot(t,k,NULL,NULL);                     //生成仅含关键字k的根结点t
	else{
		x=k;
		q=NULL;
		finish_tag=0;
		newroot_tag=0;
		while(finish_tag==0&&newroot_tag==0){
			InsertBTNode(p,i,x,q);                  //将关键字x和结点q分别插入到p->key[i+1]和p->ptr[i+1]
			if (p->keynum<=Max)
				finish_tag=1;                       //插入完成
			else{
				s=(m+1)/2;
				SplitBTNode(p,q);                 //分裂结点
				x=p->key[s];
				if(p->parent){                      //查找x的插入位置
					p=p->parent;
					i=SearchBTNode(p, x);
				}
				else                            //没找到x，需要新结点
					newroot_tag=1;
			}
		}
		if(newroot_tag==1)                      //根结点已分裂为结点p和q
			NewRoot(t,x,p,q);                   //生成新根结点t,p和q为子树指针
	}
}

void Remove(BTNode *p,int i){
	int j;
	for(j=i+1;j<=p->keynum;j++){                    //前移删除key[i]和ptr[i]
		p->key[j-1]=p->key[j];
		p->ptr[j-1]=p->ptr[j];
	}
	p->keynum--;
}

*/
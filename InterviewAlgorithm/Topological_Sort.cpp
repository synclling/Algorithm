#include<stdio.h>
#include<stdlib.h>

/*----------ջ��˳��洢�ṹ----------*/
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

typedef int ElemType;

typedef struct {
	ElemType *base;
	ElemType *top;
	int		  stacksize;
} SqStack;

int InitStack(SqStack &S){
	S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if(!S.base)	exit(-1);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1; 
} 

int StackEmpty(SqStack S){
	return (S.base == S.top)? 1 : 0;
}

int Push(SqStack &S, ElemType e){
	if((S.top - S.base) >= S.stacksize){
		S.base = (ElemType *)realloc(S.base,
			 (S.stacksize + STACK_INCREMENT) * sizeof(ElemType));
	 	if(!S.base) exit(-1);
	 	S.top = S.base + S.stacksize;
	 	S.stacksize += STACK_INCREMENT;
	}
	*S.top++ = e;
	return 1;
}

int Pop(SqStack &S, ElemType &e){
	if(S.base == S.top)	return 0;
	e = * --S.top;
	return 1;
}


/*---------- ͼ ----------*/

#define MAX_VERTEX_NUM 20
typedef char VertexType;
typedef int  InfoType;

typedef struct ArcNode {
	int 			 adjvex;
	struct ArcNode  *next;
	InfoType		info;
} ArcNode;

typedef struct VNode {
	VertexType	 data;
	ArcNode		*firstarc;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList	vertices;
	int 	vexnum, arcnum;
	int		kind;
} ALGraph;


void CreateAlGraph(ALGraph &G){
	int i, j, k, w;
	ArcNode *s;
	printf("������ͼ������(0:����ͼ 1:����ͼ):");
	scanf("%d", &G.kind);
	printf("������ͼ�Ķ������ͻ���:");
	scanf("%d, %d", &G.vexnum, &G.arcnum);
	printf("����������ͼ�Ķ���:\n");
	for(i= 0; i < G.vexnum; ++i){
		fflush(stdin);
		G.vertices[i].data = getchar();
		G.vertices[i].firstarc = NULL;
	}
	
	for(k = 0; k < G.arcnum; ++k){
		printf("������(vi - vj)���������Լ���Ӧ��Ȩֵ:");
		scanf("%d, %d, %d", &i, &j, &w);
		s = (ArcNode *)malloc(sizeof(ArcNode));
		s->adjvex = j;
		s->info = w;
		s->next = G.vertices[i].firstarc;
		G.vertices[i].firstarc = s; 
	} 
}

void FindIndegree(ALGraph G, int Indegree[]){
	int i;
	ArcNode *p;
	for(i = 0; i < G.vexnum; ++i)
		Indegree[i] = 0;
	
	for(i = 0; i < G.vexnum; ++i)
		for(p = G.vertices[i].firstarc; p; p = p->next)
			++Indegree[p->adjvex];
}


int TopologicalSort(ALGraph G){
	int i, k;
	int count = 0;			//������������ 
	int Indegree[G.vexnum];	//������������� 
	ArcNode *p;
	SqStack S;	//����0��ȶ���ջS 
	
	InitStack(S);
	FindIndegree(G, Indegree);
	
	for(i = 0; i < G.vexnum; ++i)
		if(!Indegree[i])	Push(S, i);
	
	while(!StackEmpty(S)){
		Pop(S, i);	printf("%d, %c\n", i, G.vertices[i].data);
		++count;
		for(p = G.vertices[i].firstarc; p; p = p->next){
			k = p->adjvex;
			if(--Indegree[k] == 0)	Push(S, k);
		}
	}
	if(count < G.vexnum) return 0;
	else return 1;
}

int main()
{
	ALGraph G;
	CreateAlGraph(G);
	printf("��������:\n");
	if(TopologicalSort(G))	printf("����ɹ�!\n");
	else printf("����ʧ��!\n");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

/*----------ջ��˳���洢��ʾ----------*/
typedef int ElemType;
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

typedef struct {
	ElemType	*base;
	ElemType	*top;
	int			stacksize;
} SqStack;

int InitStack(SqStack &S){
	S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if(!S.base) exit(-1);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1; 
}

int StackEmpty(SqStack S){
	return S.base == S.top? 1 : 0;
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
	if(S.top == S.base) return 0;
	e = * --S.top;
	return 1;
}


/*----------  ͼ ----------*/
typedef char VertexType;
typedef int  InfoType;
#define	MAX_VERTEX_NUM 20

typedef struct ArcNode {
	int 		    adjvex;	//�û���ָ��Ķ�����AdjList[]�е�λ��  
	struct ArcNode *next;   //ָ����һ����ָ�� 
	InfoType	    info;   //�û��������Ϣ����ΪȨֵ  
} ArcNode;	//�ڽӱ�ı��� 

typedef struct VNode{
	VertexType	 data;		//���� 
	ArcNode		*firstarc;	//ָ���һ�������ڸö���Ļ���ָ�� 
} VNode, AdjList[MAX_VERTEX_NUM];	//�ڽӱ� 

typedef struct {
	AdjList		vertices;
	int 		vexnum, arcnum;
	int 		kind;
} ALGraph;


void CreateALGraph(ALGraph &G){
	int i, j, k, w;
	ArcNode *s;
	printf("������ͼ�������־(0:����ͼ 1:����ͼ):");
	scanf("%d", &G.kind);
	printf("������ͼ�Ķ������ͻ���:");
	scanf("%d, %d", &G.vexnum, &G.arcnum);
	printf("����������ͼ�Ķ���:\n");
	for(i = 0; i < G.vexnum; ++i){
		fflush(stdin);
		G.vertices[i].data = getchar();
		G.vertices[i].firstarc = NULL;
	} 
	
	for(k = 0; k < G.arcnum; ++k){
		printf("����(vi - vj)�Ķ��������Լ���Ӧ��Ȩֵ:");
		scanf("%d, %d, %d", &i, &j, &w);
		s = (ArcNode *)malloc(sizeof(ArcNode));
		s->adjvex = j;
		s->info = w;
		s->next = G.vertices[i].firstarc;
		G.vertices[i].firstarc = s;
	} 
}

void FindIndegree(ALGraph G, int indegree[]){
	int i;
	ArcNode *p;
	for(i = 0; i < G.vexnum; ++i)
		indegree[i] = 0;
	
	for(i = 0; i < G.vexnum; ++i)
		for(p = G.vertices[i].firstarc; p; p = p->next)
			++indegree[p->adjvex];
} 

int ve[MAX_VERTEX_NUM]={0};

int TopologicalOrder(ALGraph G, SqStack &T){
	int j, k;
	int count = 0;
	ArcNode *p;
	int indegree[G.vexnum];
	SqStack S;
	
	FindIndegree(G, indegree);	//�Ը����������indegree[0...G.vexnum - 1] 
	
	InitStack(S);	//����0��ȶ���ջS 
	for(j = 0; j < G.vexnum; ++j)
		if(indegree[j] == 0)	Push(S, j);	//���Ϊ0��ջS 
	
	InitStack(T);	//�����������ж���ջT 
	
	while(!StackEmpty(S)){
		Pop(S, j);	Push(T, j);	 ++count;
		for(p = G.vertices[j].firstarc; p; p = p->next){
			k = p->adjvex;
			if(--indegree[k] == 0)	Push(S, k);
			if(ve[j] + p->info > ve[k])	ve[k] = ve[j] + p->info;
		}
	}
	if(count < G.vexnum)	return 0;
	else return 1;
}


int CriticalPath(ALGraph G){
	//GΪ�����������G�ĸ���ؼ�� 
	int i, j, k;
	int ee, el, dut;
	char tag;
	int vl[G.vexnum];
	ArcNode *p;
	SqStack T;
	if(!TopologicalOrder(G, T))	 return 0;
	
	for(i = 0; i < G.vexnum; ++i)
		vl[i] = ve[G.vexnum - 1];	//��ʼ�������¼�����ٷ���ʱ�� 
	
	while(!StackEmpty(T))	//������������������vlֵ 
		for(Pop(T, j), p = G.vertices[j].firstarc; p; p = p->next){
			k = p->adjvex;	dut = p->info;
			if(vl[k] - dut < vl[j])	 vl[j] = vl[k] - dut;
		}
	
	for(j = 0; j < G.vexnum; ++j)	//��ee��el�͹ؼ�� 
		for(p = G.vertices[j].firstarc; p; p = p->next){
			k = p->adjvex;	dut = p->info;
			ee = ve[j];		el = vl[k] - dut;
			tag = (ee == el)? '*' : ' ';
			printf("%d, %d, %d, %d, %d, %c\n", j, k, dut, ee, el, tag);
		}
	return 1;
}


int main()
{
	ALGraph G;
	CreateALGraph(G);
	printf("�ؼ��(��*��):\n");
	CriticalPath(G);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

/*----------栈的顺序表存储表示----------*/
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


/*----------  图 ----------*/
typedef char VertexType;
typedef int  InfoType;
#define	MAX_VERTEX_NUM 20

typedef struct ArcNode {
	int 		    adjvex;	//该弧所指向的顶点在AdjList[]中的位置  
	struct ArcNode *next;   //指向下一条的指针 
	InfoType	    info;   //该弧的相关信息，此为权值  
} ArcNode;	//邻接表的表结点 

typedef struct VNode{
	VertexType	 data;		//顶点 
	ArcNode		*firstarc;	//指向第一条依附于该顶点的弧的指针 
} VNode, AdjList[MAX_VERTEX_NUM];	//邻接表 

typedef struct {
	AdjList		vertices;
	int 		vexnum, arcnum;
	int 		kind;
} ALGraph;


void CreateALGraph(ALGraph &G){
	int i, j, k, w;
	ArcNode *s;
	printf("请输入图的种类标志(0:无向图 1:有向图):");
	scanf("%d", &G.kind);
	printf("请输入图的顶点数和弧数:");
	scanf("%d, %d", &G.vexnum, &G.arcnum);
	printf("请依次输入图的顶点:\n");
	for(i = 0; i < G.vexnum; ++i){
		fflush(stdin);
		G.vertices[i].data = getchar();
		G.vertices[i].firstarc = NULL;
	} 
	
	for(k = 0; k < G.arcnum; ++k){
		printf("输入(vi - vj)的顶点对序号以及对应的权值:");
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
	
	FindIndegree(G, indegree);	//对各顶点求入度indegree[0...G.vexnum - 1] 
	
	InitStack(S);	//建立0入度顶点栈S 
	for(j = 0; j < G.vexnum; ++j)
		if(indegree[j] == 0)	Push(S, j);	//入度为0进栈S 
	
	InitStack(T);	//建立拓扑序列顶点栈T 
	
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
	//G为有向网，输出G的各项关键活动 
	int i, j, k;
	int ee, el, dut;
	char tag;
	int vl[G.vexnum];
	ArcNode *p;
	SqStack T;
	if(!TopologicalOrder(G, T))	 return 0;
	
	for(i = 0; i < G.vexnum; ++i)
		vl[i] = ve[G.vexnum - 1];	//初始化顶点事件的最迟发生时间 
	
	while(!StackEmpty(T))	//按拓扑逆序求各顶点的vl值 
		for(Pop(T, j), p = G.vertices[j].firstarc; p; p = p->next){
			k = p->adjvex;	dut = p->info;
			if(vl[k] - dut < vl[j])	 vl[j] = vl[k] - dut;
		}
	
	for(j = 0; j < G.vexnum; ++j)	//求ee、el和关键活动 
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
	printf("关键活动(带*号):\n");
	CriticalPath(G);
	return 0;
}

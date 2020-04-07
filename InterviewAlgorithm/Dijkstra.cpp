#include<stdio.h>
#include<stdlib.h>


/*----------栈的顺序存储表示----------*/
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 20

typedef int SElemType;

typedef struct {
	SElemType 	*base;
	SElemType 	*top;
	int			stacksize;
} SqStack;

void Stack_Init(SqStack &S){
	S.base = (SElemType *)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
	if(!S.base)	exit(-2);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
} 

bool StackEmpty(SqStack S){
	return (S.top == S.base)? 1 : 0;
}

void Push(SqStack &S, SElemType e){
	if((S.top - S.base) >= S.stacksize){
		S.base = (SElemType *)realloc(S.base, 
			(S.stacksize + STACK_INCREMENT) * sizeof(SElemType));
		if(!S.base)	exit(-2);
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}
	*S.top++ = e;
}

void Pop(SqStack &S, SElemType &e){
	if(S.top == S.base)	return;
	e = * --S.top;
}



/*----------图----------*/
#define MAX_VERTEX_NUM 20
#define INFINITY 65535
typedef int	 VRType;		//顶点关系类型  
typedef char VertexType;	//顶点向量 

typedef struct ArcCell {
	VRType		 adj;			//VRType是顶点关系类型，对于带权图，则为权值类型 
	/*InfoType	*info;*/		//该弧相关的指针 
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; 

typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix  arcs;
	int		   vexnum, arcnum;
	int 	   kind;
} MGraph;

void CreateMGraph(MGraph &G){
	int i, j, k, w;
	printf("请输入图的种类标志(0:无向图 1:有向图):");
	scanf("%d", &G.kind);
	printf("请输入图的顶点数和弧数:");
	scanf("%d, %d", &G.vexnum, &G.arcnum);
	printf("请依次输入图的顶点:\n");
	for(i = 0; i < G.vexnum; ++i){
		fflush(stdin);
		G.vexs[i] = getchar();
	}
	
	//初始化为INT_MAX 
	for(i = 0; i < G.vexnum; ++i)
		for(j = 0; j < G.vexnum; ++j)
			G.arcs[i][j].adj = INFINITY;
	
	for(k = 0; k < G.arcnum; ++k){
		printf("请输入弧(vi, vj)的顶点序号以及权值:");
		scanf("%d, %d, %d", &i, &j, &w);
		G.arcs[i][j].adj = w;
		if(G.kind == 0) G.arcs[j][i].adj = G.arcs[i][j].adj; 
	} 
}


typedef int PathMatrix[MAX_VERTEX_NUM];
//PathMatrix[i]表示顶点vi的前驱顶点下标值 

typedef int ShortPathTable[MAX_VERTEX_NUM];
//ShortPatnTable[i]表示v0到vi顶点的最短路径权值和 

bool final[MAX_VERTEX_NUM];
//全局数组final[i]为ture表示已经求得v0到vi的最短路径


void ShorttestPath_DIJ(MGraph G, int v0, PathMatrix &P, ShortPathTable &D){
	int v, w, index, min;
	//初始化 
	for(v = 0; v < G.vexnum; ++v){
		final[v] = false;
		D[v] = G.arcs[v0][v].adj;
		P[v] = v0;
	}
	D[v0] = 0;			//v0到v0的最短路径为0 
	final[v0] = true;   //v0到v0不需要求路径 
	
	for(v = 1; v < G.vexnum; ++v){
		min = INFINITY;
		for(w = 0; w < G.vexnum; ++w)
			if(!final[w] && D[w] < min){
				min = D[w];
				index = w;
			}
			
		final[index] = true;
		
		for(w = 0; w < G.vexnum; ++w)
			if(!final[w] && (min + G.arcs[index][w].adj < D[w])){
				D[w] = min + G.arcs[index][w].adj;	//修改当前路径长度 
				P[w] = index;
			}
	}
} 

void ShowPath(PathMatrix P, SqStack &S, int v0, int v){
	SElemType e;
	int u = v;	//目标顶点 
	while(u != v0){
		Push(S, u);
		u = P[u];
	}
	Push(S, u);	//Push v0
	
	//输出路径
	while(!StackEmpty(S)){
		Pop(S, e);
		printf("%d ", e);
	}
	printf("\n");
}

int main()
{
	int v0 = 4;
	SqStack S;
	MGraph G;
	PathMatrix P;
	ShortPathTable D;
	Stack_Init(S);
	CreateMGraph(G);
	ShorttestPath_DIJ(G, v0, P, D);
	for(int v = 0; v < G.vexnum; ++v)
		if(final[v]){
			printf("V%d - V%d: ", v0, v);
			ShowPath(P, S, v0, v);
		}else{
			printf("V%d - V%d: 无路径\n", v0, v); 
		}
	return 0;
}

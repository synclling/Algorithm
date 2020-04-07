#include<stdio.h>
#include<stdlib.h>


/*----------ջ��˳��洢��ʾ----------*/
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



/*----------ͼ----------*/
#define MAX_VERTEX_NUM 20
#define INFINITY 65535
typedef int	 VRType;		//�����ϵ����  
typedef char VertexType;	//�������� 

typedef struct ArcCell {
	VRType		 adj;			//VRType�Ƕ����ϵ���ͣ����ڴ�Ȩͼ����ΪȨֵ���� 
	/*InfoType	*info;*/		//�û���ص�ָ�� 
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; 

typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix  arcs;
	int		   vexnum, arcnum;
	int 	   kind;
} MGraph;

void CreateMGraph(MGraph &G){
	int i, j, k, w;
	printf("������ͼ�������־(0:����ͼ 1:����ͼ):");
	scanf("%d", &G.kind);
	printf("������ͼ�Ķ������ͻ���:");
	scanf("%d, %d", &G.vexnum, &G.arcnum);
	printf("����������ͼ�Ķ���:\n");
	for(i = 0; i < G.vexnum; ++i){
		fflush(stdin);
		G.vexs[i] = getchar();
	}
	
	//��ʼ��ΪINT_MAX 
	for(i = 0; i < G.vexnum; ++i)
		for(j = 0; j < G.vexnum; ++j)
			G.arcs[i][j].adj = INFINITY;
	
	for(k = 0; k < G.arcnum; ++k){
		printf("�����뻡(vi, vj)�Ķ�������Լ�Ȩֵ:");
		scanf("%d, %d, %d", &i, &j, &w);
		G.arcs[i][j].adj = w;
		if(G.kind == 0) G.arcs[j][i].adj = G.arcs[i][j].adj; 
	} 
}


typedef int PathMatrix[MAX_VERTEX_NUM];
//PathMatrix[i]��ʾ����vi��ǰ�������±�ֵ 

typedef int ShortPathTable[MAX_VERTEX_NUM];
//ShortPatnTable[i]��ʾv0��vi��������·��Ȩֵ�� 

bool final[MAX_VERTEX_NUM];
//ȫ������final[i]Ϊture��ʾ�Ѿ����v0��vi�����·��


void ShorttestPath_DIJ(MGraph G, int v0, PathMatrix &P, ShortPathTable &D){
	int v, w, index, min;
	//��ʼ�� 
	for(v = 0; v < G.vexnum; ++v){
		final[v] = false;
		D[v] = G.arcs[v0][v].adj;
		P[v] = v0;
	}
	D[v0] = 0;			//v0��v0�����·��Ϊ0 
	final[v0] = true;   //v0��v0����Ҫ��·�� 
	
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
				D[w] = min + G.arcs[index][w].adj;	//�޸ĵ�ǰ·������ 
				P[w] = index;
			}
	}
} 

void ShowPath(PathMatrix P, SqStack &S, int v0, int v){
	SElemType e;
	int u = v;	//Ŀ�궥�� 
	while(u != v0){
		Push(S, u);
		u = P[u];
	}
	Push(S, u);	//Push v0
	
	//���·��
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
			printf("V%d - V%d: ��·��\n", v0, v); 
		}
	return 0;
}

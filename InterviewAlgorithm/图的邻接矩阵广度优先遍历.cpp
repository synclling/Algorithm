#include<stdio.h>
#include<malloc.h>


//----------队列的链式存储表示----------
typedef int QElemType;

typedef struct QNode {
	QElemType	  data;
	struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
	QueuePtr	front;
	QueuePtr	rear;
} LinkQueue;


void InitQueue(LinkQueue &Q){
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) exit(-2);
	Q.front->next = NULL;
}

int QueueEmpty(LinkQueue Q){
	return (Q.front == Q.rear)? 1 : 0;
}

void DestroyQueue(LinkQueue &Q){
	while(Q.front){
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear; 
	}
}

void EnQueue(LinkQueue &Q, QElemType e){
	QueuePtr p;
	if(!(p = (QueuePtr)malloc(sizeof(QNode))))
		exit(-2);
	p->data = e;	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p; 
}

void DeQueue(LinkQueue &Q, QElemType &e){
	if(Q.front == Q.rear) return;
	QueuePtr p;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p)	Q.rear = Q.front;
	free(p);
}


//----------图的邻接矩阵存储表示---------- 

#define MAX_VERTEX_NUM 20
typedef char VertexType;	//顶点类型  
typedef int VRType;			//顶点关系类型  

typedef struct ArcCell{
	VRType		 adj;	//VRType是顶点关系类型。对无权图用1或0表示是否相邻 
	/*InfoType	*info;	//该弧相关信息的指针 */ 
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	VertexType	vexs[MAX_VERTEX_NUM];	//顶点向量 
	AdjMatrix	arcs;					//邻接矩阵 
	int			vexnum, arcnum;			//图的当前顶点数和弧数  
	int 		kind;					//图的种类标志 
} MGraph;


void CreateMGraph(MGraph &G){
	int i, j, k;
	VertexType v1, v2;
	printf("请输入图的种类标志(0:无向图，1:有向图):");
	scanf("%d", &G.kind);
	printf("请输入图的顶点数和弧数:");
	scanf("%d, %d", &G.vexnum, &G.arcnum);
	printf("请依次输入图的顶点:\n");
	for(i = 0; i < G.vexnum; ++i){
		fflush(stdin);
		G.vexs[i] = getchar();
	}
	
	for(i = 0; i < G.vexnum; ++i)
		for(j = 0; j < G.vexnum; ++j)
			G.arcs[i][j].adj = 0;
	
	for(k = 0; k < G.arcnum; ++k){
		printf("输入(vi,vj)的顶点序号:");
		scanf("%d, %d", &i, &j);
		G.arcs[i][j].adj = 1;
		if(G.kind == 0)	G.arcs[j][i].adj = G.arcs[i][j].adj;
	}
	
	printf("输出邻接矩阵:\n");
	for(i = 0; i < G.vexnum; ++i){
		for(j = 0; j < G.vexnum; ++j)
			printf("%d ", G.arcs[i][j].adj);
		printf("\n");
	} 
} 

void BFSTraverse(MGraph G){
	int v, u, j;
	bool visited[G.vexnum];
	LinkQueue Q;
	InitQueue(Q);
	for(v = 0; v < G.vexnum; ++v)
		visited[v] = false;
	
	for(v = 0; v < G.vexnum; ++v){
		if(!visited[v]){
			visited[v] = true;	printf("%c ", G.vexs[v]);
			EnQueue(Q, v);
			while(!QueueEmpty(Q)){
				DeQueue(Q, u);
				for(j = 0; j < G.vexnum && G.arcs[u][j].adj == 1; ++j)
					if(!visited[j]){
						visited[j] = true;
						printf("%c ", G.vexs[j]);
						EnQueue(Q, j); 
					} 
			}
		}
	}
}


int main(int argc, char *argv[])
{
	MGraph G;
	CreateMGraph(G);
	printf("BFS:\n");
	BFSTraverse(G);
	printf("\n");
	return 0;
} 


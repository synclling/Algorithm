#include<stdio.h>
#include<malloc.h>

typedef char VertexType;
#define MAX_VERTEX_NUM 20


typedef struct ArcNode {
	int 			adjvex;	//该弧所指向的顶点在AdjList[]中的位置 
	struct ArcNode  *next;	//指向下一条弧的指针  
	/*InfoType		*info;	//该弧相关信息的指针 */ 
} ArcNode;	//邻接表的表结点  

typedef struct VNode {
	VertexType	data;		//顶点信息 
	ArcNode 	*firstarc;	//指向第一条依附该顶点的弧的指针  
} VNode, AdjList[MAX_VERTEX_NUM];  //邻接表的头结点数组  

typedef struct {
	AdjList		vertices;
	int 		vexnum, arcnum;	//图的当前顶点数和弧数 
	int 		kind;			//图的种类标志  
} ALGraph;

void CreatALGraph(ALGraph &G){
	int i, j, k;
	ArcNode *s;
	printf("请输入图的种类标志(0:无向图，1:有向图):");
	scanf ("%d", &G.kind); 
	printf("请输入图的顶点数和弧数:");
	scanf("%d, %d", &G.vexnum, &G.arcnum);
	printf("请依次输入图的顶点:\n");
	for(i = 0; i < G.vexnum; ++i){
		fflush(stdin);
		G.vertices[i].data = getchar();
		G.vertices[i].firstarc = NULL;
	} 
	
	for(k = 0; k < G.arcnum; ++k){
		printf("输入(vi - vj)的顶点对序号:");
		scanf("%d, %d", &i, &j);
		s = (ArcNode *)malloc(sizeof(ArcNode));
		s->adjvex = j;
		s->next = G.vertices[i].firstarc;	//插入表头 
		G.vertices[i].firstarc = s;
		if(G.kind == 0){	//无向图 
			s = (ArcNode *)malloc(sizeof(ArcNode));
			s->adjvex = i;
			s->next = G.vertices[j].firstarc;
			G.vertices[j].firstarc = s;
		} 
	}
} 

bool visited[MAX_VERTEX_NUM] = {false};

void DFS(ALGraph G, int v){
	ArcNode *p;
	visited[v] = true; printf("%c ",G.vertices[v].data);
	for(p = G.vertices[v].firstarc; p; p = p->next)
		if(!visited[p->adjvex])	DFS(G, p->adjvex);
}

void DFSTraverse(ALGraph G){
	int v;
	for(v = 0; v < G.vexnum; ++v)
		if(!visited[v])	 DFS(G, v);
}

int main(int argc, char *argv[])
{
	ALGraph G;
	CreatALGraph(G);
	printf("DFS:");
	DFSTraverse(G);
	printf("\n");
	return 0;
}

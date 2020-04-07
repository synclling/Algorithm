 #include<stdio.h>

#define MAX_VERTEX_NUM 	20	//最大顶点个数 

typedef int  VRType;		//顶点关系类型
typedef char VertexType;	//顶点向量  

typedef struct ArcCell {
	VRType		 adj;	//VRType是顶点关系类型。对无权图，用1或0表示相邻 
						//对于带权图，则为权值类型。  
	/*InfoType	*info;	//该弧相关的指针 */ 
} ArcCell,  AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	VertexType	vexs[MAX_VERTEX_NUM];	//顶点向量数组 
	AdjMatrix	arcs;					//邻接矩阵 
	int			vexnum, arcnum;			//图的当前顶点数和弧数 
	int			kind;					//图的种类标志  
} MGraph;



void CreateMGraph(MGraph &G){
	int i, j, k;
	VertexType v1, v2;
	printf("请输入图的种类标志(0:无向图， 1:有向图): ");
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
		printf("输入(vi - vj)的顶点序号:");
		scanf("%d, %d", &i, &j);
		G.arcs[i][j].adj = 1;
		if(G.kind == 0)		//无向图  
			G.arcs[j][i].adj = G.arcs[i][j].adj; 
	}
}

bool visited[MAX_VERTEX_NUM] = {false};

void DFS(MGraph G, int v){
	int j;
	visited[v] = true; printf("%c ",G.vexs[v]);
	for(j = 0; j < G.vexnum; ++j)
		if(G.arcs[v][j].adj != 0 && !visited[j]) DFS(G, j);
} 

void DFSTraverse(MGraph G){
	int v;
	for(v = 0; v < G.vexnum; ++v)
		if(!visited[v])	DFS(G, v);
}


int main(int argc, char *argv[])
{
	MGraph G;
	CreateMGraph(G);
	printf("DFS:\n");
	DFSTraverse(G);
	printf("\n");
	return 0;
}


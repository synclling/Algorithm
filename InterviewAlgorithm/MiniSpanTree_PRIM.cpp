#include<stdio.h>
#include<limits.h>

//----------图的邻接矩阵存储表示--------- 
#define MAX_VERTEX_NUM 20
typedef int  VRType;
typedef char VertexType;

typedef struct ArcCell {
	VRType		 adj;	//VRType顶点关系类型。对带权图，为权值类型。 
	/*InfoType  *info;	//该弧相关信息的指针 */
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	VertexType	vexs[MAX_VERTEX_NUM];
	AdjMatrix	arcs;
	int 		vexnum, arcnum;
} MGraph;

//----------辅助数组---------- 
//记录从顶点集U到V - U的代价最小的边的辅助数组定义  
typedef struct CNode {
	VertexType	adjvex;	 //存储该边依附的在U中的顶点 
	VRType		lowcost; //存储该边上的权值  
} CNode, closedge[MAX_VERTEX_NUM];


void CreateMGraph(MGraph &G){
	int i, j, k, w;
	printf("请输入的图的顶点数和弧数:");
	scanf("%d, %d", &G.vexnum, &G.arcnum);
	printf("请依次输入图的顶点:\n");
	for(i = 0; i < G.vexnum; ++i){
		fflush(stdin);
		G.vexs[i] = getchar();
	}
	
	//初始化为INT_MAX  
	for(i = 0; i < G.vexnum; ++i)
		for(j = 0; j < G.vexnum; ++j)
			G.arcs[i][j].adj = INT_MAX;
	
	for(k = 0; k < G.arcnum; ++k){
		printf("输入边(vi,vj)的顶点序号以及权值:");
		scanf("%d, %d, %d", &i, &j, &w);
		G.arcs[j][i].adj = G.arcs[i][j].adj = w;
	}
}

int LocateVex(MGraph G, VertexType u){
	int i;
	for(i = 0; i < G.vexnum; ++i)
		if(u == G.vexs[i])	return i;
	return -1;
}


int mininum(CNode record[]){
	int i, min, reserve;
	reserve = INT_MAX;
	for(i = 0; i < MAX_VERTEX_NUM; ++i){
		if(record[i].lowcost < reserve && record[i].lowcost > 0){
			reserve = record[i].lowcost;
			min = i;
		}
	}
	return min;
}

void MiniSpanTree_PRIM(MGraph G, VertexType	u){
	int i, j, k;
	CNode record[MAX_VERTEX_NUM];
	k = LocateVex(G, u);
	for(j = 0; j < G.vexnum; ++j)
		if(j != k){
			record[j].adjvex = G.vexs[k];
			record[j].lowcost = G.arcs[k][j].adj;
		} 
	record[k].lowcost = 0;	//初始，U = { u } 
	
	for(i = 1; i < G.vexnum; ++i){
		k = mininum(record);
		printf("(%c, %c)\n",record[k].adjvex, G.vexs[k]);
		record[k].lowcost = 0;	//第k顶点并入U集 
		for(j = 0; j < G.vexnum; ++j)
			if(G.arcs[k][j].adj < record[j].lowcost){
				record[j].adjvex = G.vexs[k];
				record[j].lowcost = G.arcs[k][j].adj;
			}
	}
}


int main(int argc, char *argv[])
{
	char c;
	MGraph G;
	CreateMGraph(G);
	fflush(stdin);
	printf("请输入初始顶点: ");
	scanf("%c", &c); 
	printf("最小生成树的边为:\n");
	MiniSpanTree_PRIM(G, c);
	printf("\n");
	return 0;
}


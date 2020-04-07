#include<stdio.h>
#include<limits.h> 

#define MAX_VERTEX_NUM 20	//最大顶点个数 
typedef int  VRType;
typedef char VertexType;

typedef struct ArcCell {
	VRType	adj;		//VRType是顶点关系类型。对于带权图，为权值类型。 
	/*InfoType *info; 	//该弧相关信息的指针*/ 
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	VertexType	vexs[MAX_VERTEX_NUM];	//顶点向量 
	AdjMatrix	arcs;					//邻接矩阵 
	int			vexnum, arcnum; 		//图的当前的顶点数和弧数 
} MGraph;


//----------辅助数组----------
//记录弧的邻接顶点和权值  
typedef struct ArcNode {
	int u;
	int v;
	int w;
} ArcNode;

void CreateMGraph(MGraph &G){
	int i, j, k, w;
	printf("请输入图的顶点数和弧数:");
	scanf("%d, %d", &G.vexnum, &G.arcnum);
	printf("请依次输入图的顶点:\n");
	for(i = 0; i < G.vexnum; ++i){
		fflush(stdin);
		G.vexs[i] = getchar();
	} 
	
	//初始为INT_MAX  
	for(i = 0; i < G.vexnum; ++i)
		for(j = 0; j < G.vexnum; ++j)
			G.arcs[i][j].adj = INT_MAX;
	
	for(k = 0; k < G.arcnum; ++k){
		printf("输入边(vi, vj)的顶点序号以及权值:");
		scanf("%d, %d, %d", &i, &j, &w);
		G.arcs[i][j].adj = G.arcs[j][i].adj = w;
	}
}

void swap(ArcNode record[], int i, int j){
	int tmp;
	tmp = record[i].u;
	record[i].u = record[j].u;
	record[j].u = tmp;
	
	tmp = record[i].v;
	record[i].v = record[j].v;
	record[j].v = tmp;
	
	tmp = record[i].w;
	record[i].w = record[j].w;
	record[j].w = tmp;
}

void select_sort(ArcNode record[], int n){
	int i, j;
	int index;
	for(i = 0; i < n - 1; ++i){
		index = i;
		for(j = i + 1; j < n; ++j){
			if(record[j].w < record[index].w)	index = j;
		}
		if(index != i)
			swap(record, i, index);
	}
}

void MiniSpanTree_kruskal(MGraph G){
	int i, j, k;
	int sn1, sn2;
	ArcNode record[G.arcnum];	//辅助数组，记录弧的相关信息 
	int 	vex_set[G.vexnum];	//辅助数组，描述各个顶点集的变化  
	
	//初始化辅助数组record 
	k = 0;
	for(i = 0; i < G.vexnum - 1; ++i)
		for(j = i + 1; j < G.vexnum; ++j)
			if(G.arcs[i][j].adj < INT_MAX){
				record[k].u = i;
				record[k].v = j;
				record[k].w = G.arcs[i][j].adj;
				++k;
			}
	select_sort(record, G.arcnum);	//从小到大排序  
	
	//初始化辅助数组vex_set，初始状态：每个顶点各为一个集合。 
	for(i = 0; i < G.vexnum; ++i)
		vex_set[i] = i;
	
	for(i = 0; i < G.arcnum; ++i){
		sn1 = vex_set[record[i].u];
		sn2 = vex_set[record[i].v];
		if(sn1 != sn2){
			printf("(%c, %c)\n", G.vexs[record[i].u], G.vexs[record[i].v]);
			
			for(j = 0; j < G.vexnum; ++j)	//合并集合 
				if(vex_set[j] == sn2)	vex_set[j] = sn1;
		}
	} 
}

int main(int argc, char *argv[])
{
	MGraph G;
	CreateMGraph(G);
	printf("最小生成树的弧为:\n");
	MiniSpanTree_kruskal(G);
	printf("\n");
	return 0;
} 

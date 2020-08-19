#include "Kruskal.h"
#include <iostream>

// -----弧信息-----
// 记录弧的邻接顶点和权值
typedef struct Arc
{
	int		u;	// 顶点u在G.vexs[]的index
	int		v;	// 顶点v在G.vexs[]的index
	VRType	w;
} Arc;

void ArcSwap(Arc arr[], int i, int j)
{
	Arc temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void ArcSort(Arc arr[], int n)	// 选择排序
{
	int i, j;
	int index;

	for (i = 0; i < n - 1; ++i)
	{
		index = i;
		
		for (j = i + 1; j < n; ++j)
		{
			if (arr[j].w < arr[index].w)
				index = j;
		}

		if (index != i)
			ArcSwap(arr, i, index);
	}
}

int LocateVex(const MGraph &G, VertexType v)
{
	for (int i = 0; i < G.vexnum; ++i)
	{
		if (v == G.vexs[i])	return i;
	}

	return -1;
}



void CreateMGraph(MGraph &G)
{
	int i, j, k;
	std::cout << "请输入图的顶点数和弧数: ";
	std::cin >> G.vexnum >> G.arcnum;

	std::cout << "请输入图的顶点: ";
	for (i = 0; i < G.vexnum; ++i)
	{
		std::cin >> G.vexs[i];
	}

	// 初始化邻接矩阵 INT_MAX
	for (i = 0; i < G.vexnum; ++i)
	{
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i][j].adj = INTEGER_MAX;
		}
	}

	VRType w;
	VertexType vi, vj;
	for (k = 0; k < G.arcnum; ++k)
	{
		std::cout << "请输入弧(vi, vj)的顶点vi, vj以及相应的权值: ";
		std::cin >> vi >> vj >> w;
		i = LocateVex(G, vi);
		j = LocateVex(G, vj);

		G.arcs[i][j].adj = G.arcs[j][i].adj = w;
	}
}

void MiniSpanTree_Kruskal(const MGraph &G)
{
	int i, j;
	
	Arc arr[MAX_ARC_NUM];			// 记录G所有的弧
	int vertexs[MAX_VERTEX_NUM];	// 记录每个顶点集的变化

	int k = 0;
	for (i = 0; i < G.vexnum - 1; ++i)
	{
		for (j = i + 1; j < G.vexnum; ++j)
		{
			if (G.arcs[i][j].adj < INTEGER_MAX)
			{
				arr[k].u = i;
				arr[k].v = j;
				arr[k].w = G.arcs[i][j].adj;
				++k;
			}
		}
	}

	ArcSort(arr, G.arcnum); // 按权值从小到大排序

	// 初始: 每个顶点各为一个集合
	for (i = 0; i < G.vexnum; ++i)
		vertexs[i] = i;


	for (k = 0; k < G.arcnum; ++k)
	{
		int s1 = vertexs[arr[k].u];
		int s2 = vertexs[arr[k].v];
		if (s1 != s2)
		{
			std::cout << "(" << G.vexs[arr[k].u] << ", " << G.vexs[arr[k].v] << ")" << std::endl;
			// 合并顶点集
			for (i = 0; i < G.vexnum; ++i)
			{
				if (vertexs[i] == s2)	vertexs[i] = s1;
			}
		}
	}
}
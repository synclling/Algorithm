#include "Prim.h"
#include <iostream>

// -----辅助数组-----
// 记录顶点从集合U到V-U的代价最小的边的辅助数组
typedef struct
{
	VertexType	adjvex;		// 存储该边依附的在U中的顶点
	VRType		lowcost;	// 存储该边的权值
} Closedge[MAX_VERTEX_NUM];


int LocateVex(const MGraph &G, VertexType v)
{
	for (int i = 0; i < G.vexnum; ++i)
	{
		if (v == G.vexs[i])	return i;
	}

	return -1;
}

int minimum(const Closedge &closedge)
{
	int i, min_index;
	
	VRType reserve = INTEGER_MAX;
	for (i = 0; i < MAX_VERTEX_NUM; ++i)
	{
		if (closedge[i].lowcost > 0 && closedge[i].lowcost < reserve)
		{
			min_index = i;
			reserve = closedge[i].lowcost;
		}
	}

	return min_index;
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

void MiniSpanTree_Prim(const MGraph &G, VertexType u)
{
	int i, j, k;
	Closedge closedge;		// 辅助数组

	k = LocateVex(G, u);	// 顶点u的index

	// 初始化辅助数组
	for (j = 0; j < G.vexnum; ++j)
	{
		if (j != k)
		{
			closedge[j].adjvex = u;
			closedge[j].lowcost = G.arcs[k][j].adj;
		}
	}

	closedge[k].lowcost = 0;	// 顶点u并入U集合，初始: U = { u }

	for (i = 1; i < G.vexnum; ++i)
	{
		k = minimum(closedge);
		std::cout << "(" << closedge[k].adjvex << ", " << G.vexs[k] << ")" << std::endl;
		
		closedge[k].lowcost = 0; // 第k顶点并入U集合

		for (j = 0; j < G.vexnum; ++j)
		{
			if (G.arcs[k][j].adj < closedge[j].lowcost)
			{
				closedge[j].adjvex = G.vexs[k];
				closedge[j].lowcost = G.arcs[k][j].adj;
			}
		}
	}
}
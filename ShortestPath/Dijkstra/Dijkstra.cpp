#include "Dijkstra.h"
#include <iostream>

void CreateDG(MGraph &G);
void CreateUDG(MGraph &G);


void CreateMGraph(MGraph &G)
{
	int kind;
	std::cout << "请输入图的类型(0:有向图，1:无向图，2:有向网，3:无向网): ";
	std::cin >> kind;

	switch (kind)
	{
	case 0:
		G.kind = DG;
		CreateDG(G);
		break;
	case 1:
		G.kind = UDG;
		CreateUDG(G);
		break;
	case 2:
		G.kind = DN;
		//CreateDN(G);
		break;
	case 3:
		G.kind = UDN;
		//CreateUDN(G);
		break;
	default:
		break;
	}
}

void ShortestPath(const MGraph &G, int v0, PathMatrix &P, ShortPathTable &D)
{
	int i, min;
	int v, w;

	Final final;

	for (v = 0; v < G.vexnum; ++v)
	{
		final[v] = false;
		D[v] = G.arcs[v0][v].adj;

		for (w = 0; w < G.vexnum; ++w)
			P[v][w] = false;

		if (D[v] < INTEGER_MAX)
		{
			P[v][v0] = true;
			P[v][v] = true;
		}
	}

	D[v0] = 0;
	final[v0] = true;

	for (i = 1; i < G.vexnum; ++i)
	{
		min = INTEGER_MAX;

		for (w = 0; w < G.vexnum; ++w)
		{
			if (!final[w] && D[w] < min)
			{
				v = w;
				min = D[w];
			}
		}

		final[v] = true;

		for (w = 0; w < G.vexnum; ++w)
		{
			if (!final[w] && ((min + G.arcs[v][w].adj) < D[w]))
			{
				D[w] = min + G.arcs[v][w].adj;

				for (int j = 0; j < G.vexnum; ++j)
					P[w][j] = P[v][j];

				P[w][w] = true;
			}
		}
	}
}

void PrintPath(const MGraph &G, int v0, const PathMatrix &P, const ShortPathTable &D)
{
	int i, j, k;

	// count[i]记录从源点v0到vi路径中经过的所有顶点个数，包括v0，vi
	int count[MAX_VERTEX_NUM];
	// order[]记录从源点v0到vi路径中的中间顶点的顺序，order[0]存储中间顶点的个数
	int order[MAX_VERTEX_NUM + 1];

	for (i = 0; i < G.vexnum; ++i)
	{
		count[i] = 0;
		for (j = 0; j < G.vexnum; ++j)
		{
			if (P[i][j]) // 第j顶点为路径上的顶点
			{
				count[i]++;
			}
		}
	}

	for (i = 0; i < G.vexnum; ++i)
	{
		if (i != v0)
		{
			std::cout << G.vexs[v0] << "到" << G.vexs[i] << "的最短路径为: ";
			if (count[i] > 0)
			{
				order[0] = 0;
				for (j = 0; j < G.vexnum; ++j)
					if (j != v0 && j != i && P[i][j]) // 只扫描中间顶点
					{
						int m = order[0];
						// 采用直接插入排序为v0到vi的中间顶点排序
						while (m > 0 && count[j] < count[order[m]])
						{
							order[m + 1] = order[m];
							--m;
						}
						order[m + 1] = j;
						order[0]++;
					}
				// 输出
				std::cout << G.vexs[v0] << "→";
				for (k = 1; k <= order[0]; ++k)
					std::cout << G.vexs[order[k]] << "→";
				std::cout << G.vexs[i] << ", ";
			}
			else
			{
				std::cout << "×, ";
			}

			std::cout << "权值为: ";
			if (D[i] < INTEGER_MAX)
				std::cout << D[i] << std::endl;
			else
				std::cout << "∞" << std::endl;
		}
	}
}



void CreateDG(MGraph &G)
{
	std::cout << "创建有向图..." << std::endl;

	int i, j, k;
	std::cout << "请输入有向图的顶点数和弧数: ";
	std::cin >> G.vexnum >> G.arcnum;

	std::cout << "请输入有向图的顶点: ";
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
		G.arcs[i][j].adj = w;
	}
}

void CreateUDG(MGraph &G)
{
	std::cout << "创建无向图..." << std::endl;

	int i, j, k;
	std::cout << "请输入无向图的顶点数和弧数: ";
	std::cin >> G.vexnum >> G.arcnum;

	std::cout << "请输入无向图的顶点: ";
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
		G.arcs[i][j].adj = w;
		G.arcs[j][i].adj = G.arcs[i][j].adj;
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
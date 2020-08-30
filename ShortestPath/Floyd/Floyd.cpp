#include "Floyd.h"
#include <iostream>

void CreateDG(MGraph &G);
void CreateUDG(MGraph &G);
int LocateVex(const MGraph &G, VertexType v);


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

void ShortestPath(const MGraph &G, PathMatrix &P, DistanceMatrix &D)
{
	int v, w, u;

	// 初始化
	for (v = 0; v < G.vexnum; ++v)
	{
		for (w = 0; w < G.vexnum; ++w)
		{
			D[v][w] = G.arcs[v][w].adj; // 各对顶点之间初始已知路径及距离

			for (u = 0; u < G.vexnum; ++u)
				P[v][w][u] = false;

			if (0 < D[v][w] && D[v][w] < INTEGER_MAX) // 从v到w有直接路径
			{
				P[v][w][v] = true;
				P[v][w][w] = true;
			}
		}
	}

	//for (u = 0; u < G.vexnum; ++u)
	//{
	//	for (v = 0; v < G.vexnum; ++v)
	//	{
	//		for (w = 0; w < G.vexnum; ++w)
	//		{
	//			if (D[v][u] + D[u][w] < D[v][w]) // v-u-w的路径更短
	//			{
	//				D[v][w] = D[v][u] + D[u][w];

	//				for (int i = 0; i < G.vexnum; ++i)
	//					P[v][w][i] = P[v][u][i] || P[u][w][i];
	//			}
	//		}
	//	}
	//}

	for (v = 0; v < G.vexnum; ++v)
	{
		for (w = 0; w < G.vexnum; ++w)
		{
			for (u = 0; u < G.vexnum; ++u)
			{
				if (D[v][u] + D[u][w] < D[v][w]) // v-u-w的路径更短
				{
					D[v][w] = D[v][u] + D[u][w];

					for (int i = 0; i < G.vexnum; ++i)
						P[v][w][i] = P[v][u][i] || P[u][w][i];
				}
			}
		}
	}
}

void PrintPath(const MGraph &G, const PathMatrix &P, const DistanceMatrix &D)
{
	int i, j, k;

	// temp[]记录从vi到vj路径中的中间顶点的顺序，temp[0]为中间顶点的个数
	int temp[MAX_VERTEX_NUM];
	// count[i][j]记录从vi到vj路径中的所有顶点个数，包括vi, vj
	int count[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

	for (i = 0; i < G.vexnum; ++i)
	{
		for (j = 0; j < G.vexnum; ++j)
		{
			count[i][j] = 0;
			for (k = 0; k < G.vexnum; ++k)
			{
				if (P[i][j][k]) // 第k顶点为true
				{
					count[i][j]++;
				}
			}
		}
	}

	for (i = 0; i < G.vexnum; ++i)
	{
		for (j = 0; j < G.vexnum; ++j)
		{
			if (i != j)
			{
				std::cout << G.vexs[i] << "到" << G.vexs[j] << "的最短路径为: ";
				if (count[i][j] > 0)
				{
					// 采用直接插入排序为从vi到vj路径中的中间顶点排序
					temp[0] = 0;
					for(k = 0; k < G.vexnum; ++k)
						if (k != i && k != j && P[i][j][k])
						{
							int m = temp[0];
							while (m > 0 && count[i][k] < count[i][temp[m]])
							{
								temp[m + 1] = temp[m];
								--m;
							}
							temp[m + 1] = k;
							temp[0]++;
						}
					// 输出
					std::cout << G.vexs[i] << " ";
					for (int t = 1; t <= temp[0]; ++t)
						std::cout << G.vexs[temp[t]] << " ";
					std::cout << G.vexs[j] << ", ";
				}
				else
				{
					std::cout << "x, ";
				}

				std::cout << "权值为: ";
				if (0 < D[i][j] && D[i][j] < INTEGER_MAX)
					std::cout << D[i][j] << std::endl;
				else
					std::cout << "∞" << std::endl;
			}
		}
		std::cout << std::endl;
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
			if (i == j)
				G.arcs[i][j].adj = 0;
			else
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
			if (i == j)
				G.arcs[i][j].adj = 0;
			else
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
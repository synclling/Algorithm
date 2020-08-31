#pragma once

#define MAX_VERTEX_NUM		20
#define INTEGER_MAX			0xffff

// -----图的邻接矩阵存储表示-----

// VRType: 顶点关系类型。对于无权图，用1或0表示是否相邻；对于带权图，为权值类型。
typedef int		VRType;
// VertexType: 顶点类型
typedef char	VertexType;
// GraphKind: 图的类型
typedef enum{ DG, UDG, DN, UDN } GraphKind; // 有向图，无向图，有向网，无向网
// InfoType: 弧的相关信息
typedef struct{} InfoType;

typedef struct ArcCell
{
	VRType		adj;	// VRType顶点关系类型。对于带权图，为权值类型。
	/*InfoType	*info;	// 该弧相关信息的指针，可以忽略*/
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct MGraph
{
	GraphKind	kind;					// 图的类型
	int	vexnum, arcnum;					// 图的当前顶点数和弧数
	VertexType	vexs[MAX_VERTEX_NUM];	// 顶点向量
	AdjMatrix	arcs;					// 弧的邻接矩阵
} MGraph;


// -----辅助数据结构-----

// ShortPathTable[i]表示当前找到的从源点v0到每个终点vi的最短路径的长度
typedef VRType ShortPathTable[MAX_VERTEX_NUM];
// PathMatrix[v][w]为true，则w是从源点v0到v当前求得最短路径上的顶点
typedef bool PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
// final[v]为true，表示已经求得源点v0到v的最短路径
typedef bool Final[MAX_VERTEX_NUM];



void CreateMGraph(MGraph &G);

void ShortestPath(const MGraph &G, int v0, PathMatrix &P, ShortPathTable &D);

void PrintPath(const MGraph &G, int v0, const PathMatrix &P, const ShortPathTable &D);

int LocateVex(const MGraph &G, VertexType v);
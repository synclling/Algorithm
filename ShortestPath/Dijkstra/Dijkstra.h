#pragma once

#define MAX_VERTEX_NUM		20
#define INTEGER_MAX			0xffff

// -----图的邻接矩阵存储表示-----

// VRType: 顶点关系类型。对于无权图，用1或0表示是否相邻；对于带权图，为权值类型。
typedef int		VRType;
// VertexType: 顶点类型
typedef char	VertexType;

typedef struct ArcCell
{
	VRType	adj;			// VRType顶点关系类型。对于带权图，为权值类型。
	/*InfoType *info;		// 该弧相关信息的指针*/
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct MGraph
{
	/*GraphKind	kind;					// 图的类型: 有向图、无向图、有向网、无向网*/
	int	vexnum, arcnum;					// 图的当前顶点数和弧数
	VertexType	vexs[MAX_VERTEX_NUM];	// 顶点向量
	AdjMatrix	arcs;					// 弧的邻接矩阵
} MGraph;

void CreateMGraph(MGraph &G);
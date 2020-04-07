#include<stdio.h>
#include<limits.h>

//----------ͼ���ڽӾ���洢��ʾ--------- 
#define MAX_VERTEX_NUM 20
typedef int  VRType;
typedef char VertexType;

typedef struct ArcCell {
	VRType		 adj;	//VRType�����ϵ���͡��Դ�Ȩͼ��ΪȨֵ���͡� 
	/*InfoType  *info;	//�û������Ϣ��ָ�� */
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	VertexType	vexs[MAX_VERTEX_NUM];
	AdjMatrix	arcs;
	int 		vexnum, arcnum;
} MGraph;

//----------��������---------- 
//��¼�Ӷ��㼯U��V - U�Ĵ�����С�ıߵĸ������鶨��  
typedef struct CNode {
	VertexType	adjvex;	 //�洢�ñ���������U�еĶ��� 
	VRType		lowcost; //�洢�ñ��ϵ�Ȩֵ  
} CNode, closedge[MAX_VERTEX_NUM];


void CreateMGraph(MGraph &G){
	int i, j, k, w;
	printf("�������ͼ�Ķ������ͻ���:");
	scanf("%d, %d", &G.vexnum, &G.arcnum);
	printf("����������ͼ�Ķ���:\n");
	for(i = 0; i < G.vexnum; ++i){
		fflush(stdin);
		G.vexs[i] = getchar();
	}
	
	//��ʼ��ΪINT_MAX  
	for(i = 0; i < G.vexnum; ++i)
		for(j = 0; j < G.vexnum; ++j)
			G.arcs[i][j].adj = INT_MAX;
	
	for(k = 0; k < G.arcnum; ++k){
		printf("�����(vi,vj)�Ķ�������Լ�Ȩֵ:");
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
	record[k].lowcost = 0;	//��ʼ��U = { u } 
	
	for(i = 1; i < G.vexnum; ++i){
		k = mininum(record);
		printf("(%c, %c)\n",record[k].adjvex, G.vexs[k]);
		record[k].lowcost = 0;	//��k���㲢��U�� 
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
	printf("�������ʼ����: ");
	scanf("%c", &c); 
	printf("��С�������ı�Ϊ:\n");
	MiniSpanTree_PRIM(G, c);
	printf("\n");
	return 0;
}


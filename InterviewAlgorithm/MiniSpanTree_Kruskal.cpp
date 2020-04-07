#include<stdio.h>
#include<limits.h> 

#define MAX_VERTEX_NUM 20	//��󶥵���� 
typedef int  VRType;
typedef char VertexType;

typedef struct ArcCell {
	VRType	adj;		//VRType�Ƕ����ϵ���͡����ڴ�Ȩͼ��ΪȨֵ���͡� 
	/*InfoType *info; 	//�û������Ϣ��ָ��*/ 
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	VertexType	vexs[MAX_VERTEX_NUM];	//�������� 
	AdjMatrix	arcs;					//�ڽӾ��� 
	int			vexnum, arcnum; 		//ͼ�ĵ�ǰ�Ķ������ͻ��� 
} MGraph;


//----------��������----------
//��¼�����ڽӶ����Ȩֵ  
typedef struct ArcNode {
	int u;
	int v;
	int w;
} ArcNode;

void CreateMGraph(MGraph &G){
	int i, j, k, w;
	printf("������ͼ�Ķ������ͻ���:");
	scanf("%d, %d", &G.vexnum, &G.arcnum);
	printf("����������ͼ�Ķ���:\n");
	for(i = 0; i < G.vexnum; ++i){
		fflush(stdin);
		G.vexs[i] = getchar();
	} 
	
	//��ʼΪINT_MAX  
	for(i = 0; i < G.vexnum; ++i)
		for(j = 0; j < G.vexnum; ++j)
			G.arcs[i][j].adj = INT_MAX;
	
	for(k = 0; k < G.arcnum; ++k){
		printf("�����(vi, vj)�Ķ�������Լ�Ȩֵ:");
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
	ArcNode record[G.arcnum];	//�������飬��¼���������Ϣ 
	int 	vex_set[G.vexnum];	//�������飬�����������㼯�ı仯  
	
	//��ʼ����������record 
	k = 0;
	for(i = 0; i < G.vexnum - 1; ++i)
		for(j = i + 1; j < G.vexnum; ++j)
			if(G.arcs[i][j].adj < INT_MAX){
				record[k].u = i;
				record[k].v = j;
				record[k].w = G.arcs[i][j].adj;
				++k;
			}
	select_sort(record, G.arcnum);	//��С��������  
	
	//��ʼ����������vex_set����ʼ״̬��ÿ�������Ϊһ�����ϡ� 
	for(i = 0; i < G.vexnum; ++i)
		vex_set[i] = i;
	
	for(i = 0; i < G.arcnum; ++i){
		sn1 = vex_set[record[i].u];
		sn2 = vex_set[record[i].v];
		if(sn1 != sn2){
			printf("(%c, %c)\n", G.vexs[record[i].u], G.vexs[record[i].v]);
			
			for(j = 0; j < G.vexnum; ++j)	//�ϲ����� 
				if(vex_set[j] == sn2)	vex_set[j] = sn1;
		}
	} 
}

int main(int argc, char *argv[])
{
	MGraph G;
	CreateMGraph(G);
	printf("��С�������Ļ�Ϊ:\n");
	MiniSpanTree_kruskal(G);
	printf("\n");
	return 0;
} 

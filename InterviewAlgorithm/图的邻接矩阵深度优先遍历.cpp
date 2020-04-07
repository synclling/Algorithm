 #include<stdio.h>

#define MAX_VERTEX_NUM 	20	//��󶥵���� 

typedef int  VRType;		//�����ϵ����
typedef char VertexType;	//��������  

typedef struct ArcCell {
	VRType		 adj;	//VRType�Ƕ����ϵ���͡�����Ȩͼ����1��0��ʾ���� 
						//���ڴ�Ȩͼ����ΪȨֵ���͡�  
	/*InfoType	*info;	//�û���ص�ָ�� */ 
} ArcCell,  AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	VertexType	vexs[MAX_VERTEX_NUM];	//������������ 
	AdjMatrix	arcs;					//�ڽӾ��� 
	int			vexnum, arcnum;			//ͼ�ĵ�ǰ�������ͻ��� 
	int			kind;					//ͼ�������־  
} MGraph;



void CreateMGraph(MGraph &G){
	int i, j, k;
	VertexType v1, v2;
	printf("������ͼ�������־(0:����ͼ�� 1:����ͼ): ");
	scanf("%d", &G.kind);
	printf("������ͼ�Ķ������ͻ���:");
	scanf("%d, %d", &G.vexnum, &G.arcnum);
	printf("����������ͼ�Ķ���:\n");
	for(i = 0; i < G.vexnum; ++i){
		fflush(stdin);
		G.vexs[i] = getchar();
	}
	
	for(i = 0; i < G.vexnum; ++i)
		for(j = 0; j < G.vexnum; ++j)
			G.arcs[i][j].adj = 0;
	
	for(k = 0; k < G.arcnum; ++k){
		printf("����(vi - vj)�Ķ������:");
		scanf("%d, %d", &i, &j);
		G.arcs[i][j].adj = 1;
		if(G.kind == 0)		//����ͼ  
			G.arcs[j][i].adj = G.arcs[i][j].adj; 
	}
}

bool visited[MAX_VERTEX_NUM] = {false};

void DFS(MGraph G, int v){
	int j;
	visited[v] = true; printf("%c ",G.vexs[v]);
	for(j = 0; j < G.vexnum; ++j)
		if(G.arcs[v][j].adj != 0 && !visited[j]) DFS(G, j);
} 

void DFSTraverse(MGraph G){
	int v;
	for(v = 0; v < G.vexnum; ++v)
		if(!visited[v])	DFS(G, v);
}


int main(int argc, char *argv[])
{
	MGraph G;
	CreateMGraph(G);
	printf("DFS:\n");
	DFSTraverse(G);
	printf("\n");
	return 0;
}


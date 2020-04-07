#include<stdio.h>
#include<malloc.h>

typedef char VertexType;
#define MAX_VERTEX_NUM 20


typedef struct ArcNode {
	int 			adjvex;	//�û���ָ��Ķ�����AdjList[]�е�λ�� 
	struct ArcNode  *next;	//ָ����һ������ָ��  
	/*InfoType		*info;	//�û������Ϣ��ָ�� */ 
} ArcNode;	//�ڽӱ�ı���  

typedef struct VNode {
	VertexType	data;		//������Ϣ 
	ArcNode 	*firstarc;	//ָ���һ�������ö���Ļ���ָ��  
} VNode, AdjList[MAX_VERTEX_NUM];  //�ڽӱ��ͷ�������  

typedef struct {
	AdjList		vertices;
	int 		vexnum, arcnum;	//ͼ�ĵ�ǰ�������ͻ��� 
	int 		kind;			//ͼ�������־  
} ALGraph;

void CreatALGraph(ALGraph &G){
	int i, j, k;
	ArcNode *s;
	printf("������ͼ�������־(0:����ͼ��1:����ͼ):");
	scanf ("%d", &G.kind); 
	printf("������ͼ�Ķ������ͻ���:");
	scanf("%d, %d", &G.vexnum, &G.arcnum);
	printf("����������ͼ�Ķ���:\n");
	for(i = 0; i < G.vexnum; ++i){
		fflush(stdin);
		G.vertices[i].data = getchar();
		G.vertices[i].firstarc = NULL;
	} 
	
	for(k = 0; k < G.arcnum; ++k){
		printf("����(vi - vj)�Ķ�������:");
		scanf("%d, %d", &i, &j);
		s = (ArcNode *)malloc(sizeof(ArcNode));
		s->adjvex = j;
		s->next = G.vertices[i].firstarc;	//�����ͷ 
		G.vertices[i].firstarc = s;
		if(G.kind == 0){	//����ͼ 
			s = (ArcNode *)malloc(sizeof(ArcNode));
			s->adjvex = i;
			s->next = G.vertices[j].firstarc;
			G.vertices[j].firstarc = s;
		} 
	}
} 

bool visited[MAX_VERTEX_NUM] = {false};

void DFS(ALGraph G, int v){
	ArcNode *p;
	visited[v] = true; printf("%c ",G.vertices[v].data);
	for(p = G.vertices[v].firstarc; p; p = p->next)
		if(!visited[p->adjvex])	DFS(G, p->adjvex);
}

void DFSTraverse(ALGraph G){
	int v;
	for(v = 0; v < G.vexnum; ++v)
		if(!visited[v])	 DFS(G, v);
}

int main(int argc, char *argv[])
{
	ALGraph G;
	CreatALGraph(G);
	printf("DFS:");
	DFSTraverse(G);
	printf("\n");
	return 0;
}

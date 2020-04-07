#include<stdio.h>
#include<malloc.h>


//----------���е���ʽ�洢��ʾ----------
typedef int QElemType;

typedef struct QNode {
	QElemType	  data;
	struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
	QueuePtr	front;
	QueuePtr	rear;
} LinkQueue;


void InitQueue(LinkQueue &Q){
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) exit(-2);
	Q.front->next = NULL;
}

int QueueEmpty(LinkQueue Q){
	return (Q.front == Q.rear)? 1 : 0;
}

void DestroyQueue(LinkQueue &Q){
	while(Q.front){
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear; 
	}
}

void EnQueue(LinkQueue &Q, QElemType e){
	QueuePtr p;
	if(!(p = (QueuePtr)malloc(sizeof(QNode))))
		exit(-2);
	p->data = e;	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p; 
}

void DeQueue(LinkQueue &Q, QElemType &e){
	if(Q.front == Q.rear) return;
	QueuePtr p;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p)	Q.rear = Q.front;
	free(p);
}


//----------ͼ���ڽӾ���洢��ʾ---------- 

#define MAX_VERTEX_NUM 20
typedef char VertexType;	//��������  
typedef int VRType;			//�����ϵ����  

typedef struct ArcCell{
	VRType		 adj;	//VRType�Ƕ����ϵ���͡�����Ȩͼ��1��0��ʾ�Ƿ����� 
	/*InfoType	*info;	//�û������Ϣ��ָ�� */ 
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	VertexType	vexs[MAX_VERTEX_NUM];	//�������� 
	AdjMatrix	arcs;					//�ڽӾ��� 
	int			vexnum, arcnum;			//ͼ�ĵ�ǰ�������ͻ���  
	int 		kind;					//ͼ�������־ 
} MGraph;


void CreateMGraph(MGraph &G){
	int i, j, k;
	VertexType v1, v2;
	printf("������ͼ�������־(0:����ͼ��1:����ͼ):");
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
		printf("����(vi,vj)�Ķ������:");
		scanf("%d, %d", &i, &j);
		G.arcs[i][j].adj = 1;
		if(G.kind == 0)	G.arcs[j][i].adj = G.arcs[i][j].adj;
	}
	
	printf("����ڽӾ���:\n");
	for(i = 0; i < G.vexnum; ++i){
		for(j = 0; j < G.vexnum; ++j)
			printf("%d ", G.arcs[i][j].adj);
		printf("\n");
	} 
} 

void BFSTraverse(MGraph G){
	int v, u, j;
	bool visited[G.vexnum];
	LinkQueue Q;
	InitQueue(Q);
	for(v = 0; v < G.vexnum; ++v)
		visited[v] = false;
	
	for(v = 0; v < G.vexnum; ++v){
		if(!visited[v]){
			visited[v] = true;	printf("%c ", G.vexs[v]);
			EnQueue(Q, v);
			while(!QueueEmpty(Q)){
				DeQueue(Q, u);
				for(j = 0; j < G.vexnum && G.arcs[u][j].adj == 1; ++j)
					if(!visited[j]){
						visited[j] = true;
						printf("%c ", G.vexs[j]);
						EnQueue(Q, j); 
					} 
			}
		}
	}
}


int main(int argc, char *argv[])
{
	MGraph G;
	CreateMGraph(G);
	printf("BFS:\n");
	BFSTraverse(G);
	printf("\n");
	return 0;
} 


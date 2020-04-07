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


//----------ͼ���ڽӱ�洢��ʾ---------- 

#define MAX_VERTEX_NUM 20
typedef char VertexType;

typedef struct ArcNode {
	int 		    adjvex;	//�û���ָ��Ķ�����AdjList[]�е�λ��  
	struct ArcNode *next;	//ָ����һ������ָ��  
} ArcNode;	//�ڽӱ�ı���

typedef struct VNode {
	VertexType	 data;		//������Ϣ  
	ArcNode 	*firstarc;	//ָ���һ�������ö���Ļ���ָ��  
} VNode, AdjList[MAX_VERTEX_NUM]; //�ڽӱ��ͷ������� 

typedef struct {
	AdjList		vertices;
	int 		vexnum, arcnum;	//ͼ�ĵ�ǰ�������ͻ���  
	int 		kind;			//ͼ�������־  
} ALGraph;


void CreateALGraph(ALGraph &G){
	int i, j, k;
	ArcNode *s;
	printf("������ͼ�������־(0:����ͼ��1:����ͼ):");
	scanf("%d", &G.kind);
	printf("������ͼ�Ķ������ͻ���:");
	scanf("%d,%d", &G.vexnum, &G.arcnum);
	printf("����������ͼ�Ķ���:\n");
	for(i = 0; i < G.vexnum; ++i){
		fflush(stdin);
		G.vertices[i].data = getchar();
		G.vertices[i].firstarc = NULL; 
	}
	
	for(k = 0; k < G.arcnum; ++k){
		printf("����(vi - vj)�Ķ�������:");
		scanf("%d,%d", &i, &j);
		s = (ArcNode *)malloc(sizeof(ArcNode));
		s->adjvex = j;
		s->next = G.vertices[i].firstarc;
		G.vertices[i].firstarc = s;
		if(G.kind == 0){
			s = (ArcNode *)malloc(sizeof(ArcNode));
			s->adjvex = i;
			s->next = G.vertices[j].firstarc;
			G.vertices[j].firstarc = s;
		}
	}
} 


void BFSTraverse(ALGraph G){
	int v, u;
	LinkQueue Q;
	ArcNode *p;
	bool visited[G.vexnum];
	for(v = 0; v < G.vexnum; ++v)	visited[v] = false;
	InitQueue(Q);
	for(v = 0; v < G.vexnum; ++v){
		if(!visited[v]){
			visited[v] = true;	printf("%c", G.vertices[v].data);
			EnQueue(Q, v);
			while(!QueueEmpty(Q)){
				DeQueue(Q, u);
				for(p = G.vertices[u].firstarc; p; p = p->next)
					if(!visited[p->adjvex]){
						visited[p->adjvex] = true;
						printf("%c", G.vertices[p->adjvex].data);
						EnQueue(Q, p->adjvex);
					}
			} 
		}
	}
}

int main(int argc, char *argv[])
{
	ALGraph G;
	CreateALGraph(G);
	printf("BFS:\n");
	BFSTraverse(G);
	printf("\n");
	return 0;
}

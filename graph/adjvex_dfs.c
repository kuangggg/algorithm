#include <stdio.h>
#include <stdlib.h>

#define MAX_VEX 20

//邻接表

typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode {
	//邻接域，定点下表
	int adjvex;
	EdgeType weight;
	struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode {
	VertexType data;
	EdgeNode *first;
} VertexNode, AdjList[MAX_VEX];

typedef struct {
	AdjList adjList;
	int vexNum, arcNum;	
} Graph;

void printGraph(Graph *g)
{
	int i;
	printf("打印邻接表\n");
	for(i = 0; i < g->vexNum; i++) {
		printf("[%d] 顶点 %c", i+1, g->adjList[i].data);	

		EdgeNode *e = g->adjList[i].first;
		while(e != NULL) {
			printf("<%c, %c> %d ", g->adjList[i].data, g->adjList[e->adjvex].data, e->weight);	
			e = e->next;
		}
		putchar('\n');
	}
}

int locateVex(Graph *g, VertexType v)
{
	int i;
	for(i = 0; i < g->vexNum; i++) {
		if(v == g->adjList[i].data)	
			break;
	}
	
	return i;
}

void createGraph(Graph *g)
{
	int i, ch, w;
	char v1, v2;

	printf("请输入顶点数和边数：\n");
	scanf("%d,%d", &g->vexNum, &g->arcNum);
	getchar();

	for(i = 0; i < g->vexNum; i++) {
		printf("请输入顶点 %d\n", i+1);	
		ch = getchar();
		while(getchar() != '\n');
		g->adjList[i].data = ch;
	}

	g->adjList[i].first = NULL;

	printf("请按照如下格式输入顶点和权重\n");
	printf("v1 v2 w\n");

	for(i = 0; i < g->arcNum; i++) {
		scanf("%c %c %d", &v1, &v2, &w);		
		getchar();
		
		int m = locateVex(g, v1);
		int n = locateVex(g, v2);

		EdgeNode *e = (EdgeNode*)malloc(sizeof(EdgeNode));
		if(e == NULL) {
			perror("malloc");	
		}

		e->adjvex = n;
		e->weight = w;
		//头插法
		e->next = g->adjList[m].first;
		
		g->adjList[m].first = e;
	}
}

int visited[MAX_VEX];

void dfs(Graph *g, int i)
{
	EdgeNode *e;
	visited[i] = 1;
	printf("%c ", g->adjList[i].data);

	for(e = g->adjList[i].first; e != NULL; e = e->next)
		if(!visited[e->adjvex])
			dfs(g, e->adjvex);

}

void main()
{
	printf("邻接表\n");
	
	Graph g;

	createGraph(&g);

	printGraph(&g);

	dfs(&g, 0);
}







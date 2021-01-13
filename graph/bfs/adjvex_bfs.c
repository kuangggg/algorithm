#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 10

//邻接表的广度搜索

typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode_ {
	int adjvex;
	EdgeType weight;
	struct EdgeNode_ *next;
} EdgeNode;

typedef struct VertexNode_ {
	VertexType data;
	EdgeNode *firstedge;
} VertexNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList adjList;
	int VertexNum, EdgeNum;
} Graph;

int locateVertex(Graph *g, VertexType v);

void createGraph(Graph *g)
{
	int i, w;
	char src, dst;

	printf("创建邻接表矩阵\n");
	printf("请输入顶点数和边数,空格分隔\n");
	scanf("%d %d", &g->VertexNum, &g->EdgeNum);
	getchar();
	
	for(i = 0; i < g->VertexNum; i++ ) {
		printf("请输入第%d个顶点\n", i+1);
		scanf("%c", &g->adjList[i].data);	
		getchar();
		g->adjList[i].firstedge = NULL;
	}	

	for(i = 0; i < g->EdgeNum; i++) {
		printf("请输入起始顶点权重，用空格隔开\n");
		scanf("%c %c %d", &src, &dst, &w);	
		getchar();

		EdgeNode *edgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
		edgeNode->adjvex = locateVertex(g, dst);
		edgeNode->weight = w;

		//头插法
		edgeNode->next = g->adjList[i].firstedge;
		g->adjList[i].firstedge = edgeNode;


		//无向图对称操作
		edgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
		edgeNode->adjvex = locateVertex(g, src);
		edgeNode->weight = w;

		edgeNode->next = g->adjList[locateVertex(g, dst)].firstedge;
		g->adjList[locateVertex(g, dst)].firstedge = edgeNode;
	}
}

int locateVertex(Graph *g, VertexType v)
{
	int i;
	for(i = 0; i < g->VertexNum; i++) {
		if(v == g->adjList[i].data)	
			break;
	}
	return i;
}

void printGraph(Graph *g)
{
	int i;
	printf("打印邻接表图\n");

	for(i = 0; i < g->VertexNum; i++) {
		printf("打印顶点 %c |", g->adjList[i].data);	

		EdgeNode *e = g->adjList[i].firstedge;
		while(e) {
			printf("<%c %c>%d ", g->adjList[i].data, g->adjList[e->adjvex].data, e->weight);	
			e = e->next;
		}
		putchar('\n');
	}
}


int main()
{
	Graph g;
	createGraph(&g);
	printGraph(&g);
	return 0;
}


#include <stdio.h>

#define VERTEX_NUM 4
#define INFINITY 9999


//图的邻接矩阵存储法

typedef char vertexType;
typedef int edgeType;

typedef struct {
	vertexType vexs[VERTEX_NUM];
	edgeType arc[VERTEX_NUM][VERTEX_NUM];
	int vexNum, arcNum;
} Graph;

int locateVex(Graph *g, vertexType v);

void createGraph(Graph *g)
{
	int i, j, ch, inputCount;
	edgeType w;
	
	printf("please input vertex and edge :\n");
	inputCount = scanf("%d %d", &g->vexNum, &g->arcNum);
	printf("the input count is %d\n", inputCount);

	//清除残留 \n
	getchar();
	printf("----------------------------\n");
	printf("please input vertex char\n");

	for(i = 0; i < g->vexNum; i++) {

		ch = getchar();
		while(getchar() != '\n');
		printf("vertex %d input char is %d %c\n", i+1, ch, ch);
		g->vexs[i] = ch;
	}	

	for(i = 0; i < g->vexNum; i++)
		printf("\t%c", g->vexs[i]);

	putchar('\n');

	for(i = 0; i < g->vexNum; i++) {
		for(j = 0; j < g->vexNum; j++) {
			g->arc[i][j] = INFINITY;	
		}	
	}

	printf("please input (vi, vj) 和权重 w\n");

	for(i = 0; i < g->arcNum; i++) {
		char v1, v2;	
		scanf("%c %c %d", &v1, &v2, &w);
		getchar();
		int m = locateVex(g, v1);
		int n = locateVex(g, v2);
		printf("vertex %d %d fill %d\n", m, n, w);
		if(m == -1 || n == -1)
			return;

		g->arc[m][n] = w;
		g->arc[n][m] = w;
	}
}

void printGraph(Graph *g)
{
	int i, j;
	for(i = 0; i < g->vexNum; i++) {
		for(j = 0; j < g->vexNum; j++)	
			printf("\t%d", g->arc[i][j]);
		putchar('\n');
	}
}

int locateVex(Graph *g, vertexType v)
{
	int i;
	for(i = 0; i < g->vexNum; i++)
		if(g->vexs[i] == v)
			break;

	if(i > g->vexNum)
		return -1;
	return i;
}

void main()
{
	Graph g;
	createGraph(&g);
	printGraph(&g);
}


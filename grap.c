#include <stdio.h>

#define VERTEX_NUM 4
#define INFINITY 9999

typedef char vertexType;
typedef int edgeType;

typedef struct {
	vertexType vexs[VERTEX_NUM];
	edgeType arc[VERTEX_NUM][VERTEX_NUM];
	int vexNum, arcNum;
} Graph;

void createGraph(Graph *g)
{
	int i, j, ch;
	
	printf("please input vertex and edge :\n");
	
	scanf("%d,%d", &g->vexNum, &g->arcNum);

	for(i = 0; i < g->vexNum; i++) {
		printf("please input vertex %d\n", i+1);
		
		scanf(&g->vexs[i]);		
	}	

	for(i = 0; i < g->vexNum; i++) {
		printf("%6c", g->vexs[i]);	
	}
	
	for(i = 0; i < g->vexNum; i++) {
		for(j = 0; j < g->vexNum; j++) {
			g->arc[i][j] = INFINITY;	
		}	
	}

	printf("created graph\n");	
}

void printGraph(Graph *g)
{
	int i, j;
	for(i = 0; i < g->vexNum; i++) {
		for(j = 0; j < g->vexNum; j++)	
			printf("%10d", g->arc[i][j]);
		putchar('\n');
	}

}

void main()
{
	Graph g;

	createGraph(&g);
	printGraph(&g);

}


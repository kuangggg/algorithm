#include <stdio.h>
#include <queue>

#define MAX_VERTEX_NUM 100

//邻接矩阵表示图的广度优先搜索

typedef struct Graph_ {
	char vexs[MAX_VERTEX_NUM];	
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum, arcnum;
} Graph;

int locateVex(Graph *g, char v)
{
	int i = 0;
	for(; i < g->vexnum; i ++) {
		if(g->vexs[i] == v)	
			return i;
	}
}

void createGraph(Graph *g)
{
	int i, j, x, y;
	char src, dst;

	printf("请输入需要创建图的顶点数和边数,使用空格分开\n");
	scanf("%d %d", &g->vexnum, &g->arcnum);
	getchar();

	printf("请输入各顶点符号\n");
	for(i = 0; i < g->vexnum; i++) {
		scanf("%c", &g->vexs[i]);
		getchar();
		printf("你输入的符号 %c\n", g->vexs[i]);
	}

	for(i = 0; i < g->vexnum; i++) {
		for(j = 0; j < g->vexnum; j++)	
			g->arcs[i][j] = 0;
	}

	for(i = 0; i < g->arcnum; i++) {
		printf("请输入连线的两个顶点,空格分开\n");	
		scanf("%c %c", &src, &dst);
		while(getchar() != '\n');

		x = locateVex(g, src);	
		y = locateVex(g, dst);	

		g->arcs[x][y] = g->arcs[y][x] = 1;
	}
}

void printGraph(Graph *g)
{
	printf("\n打印图:");
	printf("此图有 %d 顶点 %d 边\n", g->vexnum, g->arcnum);

	int i, j;
	for(i = 0; i < g->vexnum; i++) {
		for(j = 0; j < g->vexnum; j++)
			printf("\t%d", g->arcs[i][j]);
		putchar('\n');
	}
}

void bfs(Graph *g, char v)
{
	printf("广度优先遍历打印节点\n");
	//核心在于每个节点出队列后把全部相邻没有访问过的节点再入队列
	//出队列的顺序就是层序广度优先

	using namespace std;
	queue<char> q;	
	char u;
	int i, srcIdx;

	bool visited[MAX_VERTEX_NUM];

	int idx = locateVex(g, v);
	printf("%c ", v);	
	
	visited[idx] = true;
	q.push(v);
	
	while(!q.empty()) {
		u = q.front(); 	
		srcIdx = locateVex(g, u);
		q.pop();

		for(i = 0; i < g->vexnum; i++) {
			if(g->arcs[srcIdx][i] && !visited[i]){
				printf("%c ", g->vexs[i]);	
				q.push(g->vexs[i]);
				visited[i] = true;
			}
		}
	}
	putchar('\n');
}


int main()
{
	Graph g;	
	createGraph(&g);
	printGraph(&g);
	bfs(&g, 'a');
	
	return 0;
}

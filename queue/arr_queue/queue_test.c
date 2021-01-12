#include "queue.h"
#include <stdio.h>


int main()
{
	Queue q;
	Status res;
	ElementType e;

	InitQueue(&q);
	
	printf("init front %d  rear %d\n", q.front, q.rear);
	res = EnQueue(&q, 1);
	printf("enqueue front %d  rear %d ret %d\n", q.front, q.rear, res);
	res = EnQueue(&q, 2);
	printf("enqueue front %d  rear %d ret %d\n", q.front, q.rear, res);
	res = EnQueue(&q, 3);
	printf("enqueue front %d  rear %d ret %d\n", q.front, q.rear, res);
	res = EnQueue(&q, 4);
	printf("enqueue front %d  rear %d ret %d\n", q.front, q.rear, res);
	res = EnQueue(&q, 5);
	printf("enqueue front %d  rear %d ret %d\n", q.front, q.rear, res);
	res = EnQueue(&q, 6);
	printf("enqueue front %d  rear %d ret %d\n", q.front, q.rear, res);

	res = DeQueue(&q, &e);
	printf("dequeue front %d  rear %d ret %d e %d\n", q.front, q.rear, res, e);

	res = DeQueue(&q, &e);
	printf("dequeue front %d  rear %d ret %d e %d\n", q.front, q.rear, res, e);

	return 0;
}

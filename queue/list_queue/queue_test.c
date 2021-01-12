#include <stdio.h>
#include "queue.h"

main()
{
	
	Queue q;
	Status ret;
	ElementType e;

	QueueInit(&q);

	ret = EnQueue(&q, 1);
	printf("enqueue ret %d e %d\n", ret, 1);

	ret = EnQueue(&q, 2);
	printf("enqueue ret %d e %d\n", ret, 2);
	
	ret = EnQueue(&q, 3);
	printf("enqueue ret %d e %d\n", ret, 3);

	ret = DeQueue(&q, &e);		
	printf("dequeue ret %d res %d\n", ret, e);

	printf("the queue is empty %d\n", QueueEmpty(&q));
	
	ret = DeQueue(&q, &e);		
	printf("dequeue ret %d res %d\n", ret, e);

	ret = DeQueue(&q, &e);		
	printf("dequeue ret %d res %d\n", ret, e);

	ret = DeQueue(&q, &e);		
	printf("dequeue ret %d res %d\n", ret, e);

	printf("the queue is empty %d\n", QueueEmpty(&q));
}

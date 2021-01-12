#include "queue.h"

Status InitQueue(Queue *q)
{
	q->front = q->rear = 0;
	return OK;
}

Status QueueFull(Queue *q)
{
	return (q->rear + 1) % MAX_SIZE == q->front ? OK : FAIL;
}

Status QueueEmpty(Queue *q)
{
	return q->rear == q->front ? OK : FAIL;
}

Status EnQueue(Queue *q, ElementType e)
{
	if(QueueFull(q)) {
		return FAIL;	
	}

	q->data[q->rear] = e;	
	q->rear = (q->rear + 1) % MAX_SIZE;
	return OK;
}

Status DeQueue(Queue *q, ElementType *e)
{
	if(QueueEmpty(q))
		return FAIL;
	*e = q->data[q->front];
	q->front = (q->front + 1) % MAX_SIZE;
	return OK;
}






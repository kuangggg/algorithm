#include <stdio.h>
#include "queue.h"
#include <stdlib.h>

void QueueInit(Queue *q)
{
	QueuePtr headNode = (QueuePtr)malloc(sizeof(Node));
	if(!headNode) {
		perror("malloc");	
		exit(EXIT_FAILURE);
	}

	q->front = headNode;
	q->rear = headNode;
}

Status EnQueue(Queue *q, ElementType e)
{
	QueuePtr new = (QueuePtr)malloc(sizeof(Node));
	if(!new) {
		perror("malloc");	
		return ERROR;
	}
	
	new->data = e;
	new->next = NULL;

	q->rear->next = new;
	q->rear = new;
	return OK;
}

Status DeQueue(Queue *q, ElementType *e)
{
	if(q->front == q->rear)
		return ERROR;

	QueuePtr delNode = q->front->next;	
	*e = delNode->data;	

	q->front->next = delNode->next;

	if(q->rear == delNode)
		q->rear = q->front;

	free(delNode);	
	
	return OK;
}

Status QueueEmpty(Queue *q)
{
	return q->front == q->rear ? OK : ERROR;
}



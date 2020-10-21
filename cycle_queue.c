#include <stdio.h>
#include <stdlib.h>
#define SIZE 5 

typedef struct Queue_ {
	int data[SIZE];
	int rear;	
	int front;
} Queue;

Queue* init()
{
	Queue *q = (Queue*)malloc(sizeof(Queue));
	if(q == NULL){
		exit(0);
	}	
	q->rear = 0;
	q->front = 0;
	return q;
}

void push(Queue *q, int data)
{
	if((q->rear+1)%SIZE == q->front) {
		printf("queue is full\n");	
		return;
	} else {
		printf("-> %d\n", data);
		q->data[q->rear] = data;
		q->rear = (q->rear+1)%SIZE;
	}
}

void pop(Queue *q)
{
	if(q->front == q->rear) {
		printf("queue is empty");
		return;
	} else {
		printf("%d ->\n", q->data[q->front]);
		q->data[q->front] = 0;
		q->front = (q->front+1)%SIZE;
	}
}

void print(Queue *q)
{
	printf("print queue \n");

	int idx = q->front;
	while(idx != q->rear) {
		printf("- %d\n", q->data[idx]);
		idx = (idx+1)%SIZE;
	}
}

int main()
{
	Queue *q = init();	
	push(q, 1);	
	push(q, 2);	
	push(q, 3);	
	pop(q);	
	pop(q);	
	pop(q);	
	push(q, 4);	
		
	print(q);
	return 0;
}

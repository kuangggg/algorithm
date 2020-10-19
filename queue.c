#include <stdlib.h>
#include <stdio.h>

typedef struct Node_ {
	struct Node_ *next;
	int data;
}Node;

typedef struct Queue_ {
	Node *rear;
	Node *front;
} Queue;

Node* init_node()
{
	Node *new = (Node*)malloc(sizeof(Node));
	if(new == NULL) {
		exit(0);
	}
	return new;
}

Queue* queue_init()
{
	Queue *q = (Queue*)malloc(sizeof(Queue));
	if(q == NULL) {
		exit(0);
	}
	q->front = NULL;
	q->rear = NULL;
	return q;
}

int empty(Queue *q)
{
	return q->rear == NULL;
}

void queue_push(Queue *q, int data)
{
	Node *new = init_node();
	new->data = data;
	new->next = NULL;

	printf("%d -> queue\n", data);
	
	if(empty(q)) {
		q->front = new;
		q->rear = new;
	} else {
		q->rear->next = new;
		q->rear = new;
	}
}

void queue_print(Queue *q)
{
	Node *cur = init_node();
	cur = q->front;

	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;	
	}
}

void queue_pop(Queue *q)
{
	Node *cur = q->front;
	
	if(empty(q)) {
		return;	
	}

	if(q->front == q->rear) {
		q->front = NULL;	
		q->rear = NULL;
	} else {
		q->front = q->front->next;	
	}
	free(cur);
}

int main()
{
	Queue *q = queue_init();

	queue_push(q, 1);
	queue_push(q, 2);
	queue_push(q, 3);
	
	queue_print(q);

	printf("pop from queue\n");
	queue_pop(q);
	queue_print(q);
	return 0;
}

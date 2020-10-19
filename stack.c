#include <stdio.h>
#include <stdlib.h>

typedef struct Node_ {
	struct Node_ *next;
	int data;
} Node;

typedef struct Stack_ {
	Node *top;
	int count;
} Stack;

Stack* stack_push(Stack *p, int element)
{
	Node *new = (Node*)malloc(sizeof(Node));
	if(new == NULL) {
		exit(0);
	}

	new->data = element;
	new->next = p->top;
	p->top = new;
	p->count++;

	return p;
}

Stack* stack_pop(Stack *p)
{
	Node *del_node = p->top;
	
	p->top = p->top->next;

	free(del_node);
	p->count--;

	return p;
}

void stack_print(Stack *s)
{
	Node *cur = s->top;
	
	while(cur != NULL) {
		printf("%d\n", cur->data);	
		cur = cur->next;
	}
}

Stack* init()
{
	Stack *s = (Stack*)malloc(sizeof(Stack));
	if(s == NULL) {
		exit(0);
	}
	s->top = NULL;
	s->count = 0;	
	return s;	
}

int main()
{
	Stack *s = init();
	printf("stack push 1\n");
	stack_push(s, 1);
	printf("stack push 2\n");
	stack_push(s, 2);
	printf("stack push 3\n");
	stack_push(s, 3);
	printf("the num of stack %d\n", s->count);
	
	stack_print(s);	
}

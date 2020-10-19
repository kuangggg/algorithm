#include <stdio.h>
#include <stdlib.h>

typedef struct Node_ {
	struct Node_ *next;
	int data;
}Node;

Node* init()
{

	Node *h = (Node*)malloc(sizeof(Node));
	if(h == NULL) {
		printf("alloc fail\n");	
		exit(0);
	}
	h->next = NULL;
	return h;
}

void list_insert(Node *h)
{
	int data;
	printf("input the data\n");
	scanf("%d\n", &data);

	Node *n = init();
	n->data = data;

	if(h != NULL) {
		Node *cur = h;
		while(cur->next != h) {
			cur = cur->next;	
		}
		cur->next = n;
		n->next = h;
		printf("insert success\n");
	}
}

void print_list(Node *h)
{
	if(h != NULL) {
		Node *cur = h;	
		while(cur->next != h) {
			printf("%d\n", cur->next->data);
			cur = cur->next;	
		}
	} else {
		printf("no data in list\n");
	}
}

int main()
{
	Node *h = init();

	h->next = h;

	list_insert(h);
	list_insert(h);
	list_insert(h);
	print_list(h);
	return 0;
}

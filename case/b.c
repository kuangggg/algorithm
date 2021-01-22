#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
//打印链表倒数第N个节点

typedef struct Node_{
	struct Node_ *next;
	int data;
} Node; 

Node* init_list()
{
	Node *head;
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;

	int x;
	Node *cur;
	cur = head;

	while(scanf("%d", &x) != EOF) {
		Node *new = (Node*)malloc(sizeof(Node));	
		new->data = x;
		printf("the node is created -> %d\n", x);

		cur->next = new;
		cur = new;
	}

	cur->next = NULL;
	return head;
}

void print_list(Node *h)
{
	printf("print the list\n");
	Node *cur = h->next;
	while(cur) {
		printf("%d\n", cur->data);	
		cur = cur->next;
	}
}

void print_pos(Node *h, int pos)
{
	Node *cur, *offset, *pre;	
	cur = h->next;
	pre = h->next;
	
	int i;	
	for(i = 1; i < pos; i++) {
		pre = pre->next;	
	}
	
	while(pre->next) {
		cur = cur->next;	
		pre = pre->next;	
	}	

	printf("倒数第 %d 节点是 %d\n", pos, cur->data);
}

void main()
{
	Node *h = init_list();
	print_list(h);	
	print_pos(h, 3);
}

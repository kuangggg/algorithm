#include <stdio.h>
#include <stdlib.h>

typedef struct Node_ {
	struct Node_ *pre;
	struct Node_ *next;
	int data;
} Node;


Node* init()
{
	int len;
	int num = 1;
	int input;
	printf("the len of link\n");
	scanf("%d", &len);
	
	Node *h = (Node*)malloc(sizeof(Node));

	h->pre = NULL;
	h->next = NULL;
	
	printf("input %d number\n", num++);
	scanf("%d", &input);
	h->data = input;

	Node *cur = h;
	while(num <= len) {
		Node *new = (Node*)malloc(sizeof(Node));	
		new->pre = NULL;
		new->next = NULL;
		printf("input %d number\n", num++);
		scanf("%d", &input);
		new->data = input;

		cur->next = new;
		new->pre = cur;
		cur = cur->next;
	}

	return h;
}

void print_list(Node* h)
{
	printf("print the list \n");
	Node *cur = h;
	while(cur){
		printf("%d\n", cur->data);
		cur = cur->next;
	}
}

Node* list_insert(Node *h, int pos, int data)
{
	int i;
	Node *new = (Node*)malloc(sizeof(Node));	
	new->data = data;
	new->pre = NULL;
	new->next = NULL;
	//头结点插入
	if(pos == 1) {
		h->pre = new;
		new->next = h;
		h = new;
	} else {
		Node *cur = h;
		for(i = 1; i<pos-1; i++) {
			cur = cur->next;
		}
		if(cur->next) {
			new->pre = cur;
			new->next = cur->next;
			cur->next = new;
			cur->next->pre = new;
		//尾结点插入
		} else {
			cur->next = new;
			new->pre = cur;
		}
	}
	return h;
}

Node* list_del(Node* h, int data)
{
	Node *cur = h;

	while(cur) {
		if(cur->data == data) {
			cur->pre->next = cur->next;
			cur->next->pre = cur->pre;
			free(cur);
			printf("del %d success\n", data);
			return h;
		}
		
		cur = cur->next;
	}
	printf("not found the %d\n", data);
	return h;
}


int main()
{

	Node *h = init();
	print_list(h);
	//list_insert(h, 4, 23);
	//print_list(h);
	list_del(h, 33);

	return 0;
}

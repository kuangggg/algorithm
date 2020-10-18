#include <stdio.h>
#include <stdlib.h>


//单列表的插入修改删除

typedef struct Node_ {
	int data;
	struct Node_ *next;
} Node;

Node* list_insert()
{
	Node *l;
	l = (Node*)malloc(sizeof(Node));

	if(l == NULL) {
		printf("alloc fail");	
		exit(0);
	}

	l->next = NULL;

	int x;
	while(scanf("%d", &x) != EOF) {
		Node *new;

		new = (Node*)malloc(sizeof(Node));
		new->data = x;
		new->next = l->next;
		l->next = new;
		printf("thie new node is created -> %d\n", x);
	}
	return l;
}

Node* list_insert_tail()
{
	Node *head;
	head = (Node*)malloc(sizeof(Node));
	if(head == NULL){
		printf("alloc fail");
		exit(0);
	}
	head->next = NULL;

	int x;
	Node *cur;
	cur = head;
	
	while(scanf("%d", &x) != EOF) {
		Node *new = (Node*)malloc(sizeof(Node));	
		new->data = x;
		printf("thie new node is created -> %d\n", x);

		cur->next = new;
		cur = new;
	}
	cur->next = NULL;
	return head;
}

void print_list(Node* h)
{
	printf("print the list\n");
	Node *cur = h->next;
	
	while(cur) {
		printf("%d\n", cur->data);	
		cur = cur->next;
	}
}

void replace(Node *head, int obj, int replace)
{
	Node *cur = head->next;
	while(cur) {
		if(cur->data == obj) {
			cur->data = replace;	
		}	
		cur = cur->next;
	}
}

//节点i插入
Node* list_pos_insert(Node *h, int i, int x)
{
	Node *pre;
	pre = h;
	int j;
	for(j = 1; j < i; j++) {
		pre = pre->next;
	}

	Node *new = (Node*)malloc(sizeof(Node));
	new->data = x;
	new->next = pre->next;
	pre->next = new;
	
	return h;
}

Node* list_rm(Node *h, int x)
{
	Node *cur, *pre;
	cur = h->next;
	
	while(cur->data != x) {
		pre = cur;
		cur = cur->next;
	}
	
	pre->next = cur->next;
	free(cur);
	return h;
}


int main()
{

	//Node* list = list_insert();	
	Node *list = list_insert_tail();
	print_list(list);
	//printf("thie pos 3 insert 11");
	//list_pos_insert(list, 3, 11);
	//print_list(list);
	//printf("replace 23 -> 33 \n");
	//replace(list, 23, 33);
	list_rm(list, 3);
	print_list(list);
	return 0;
}

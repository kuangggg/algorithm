#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
//头插尾插初始化list

typedef struct Node_ {
	struct Node_ *next;
	int data;	
} Node;

Node* make_node(int val)
{
	Node *n = (Node*)malloc(sizeof(Node));
	n->data = val;
	n->next = NULL;
	return n;
}

Node* init_list(int *arr, int len)
{
	int i;
	Node *head, *pre;	
	head = make_node(0);

	pre = head;
	for(i = 0; i<len; i++) {
		Node *new = make_node(arr[i]);
		pre->next = new;
		pre = new;
	}	
	
	return head;
}

void insert_node(Node *h, int pos, int data)
{
	Node *pre, *new;	
	pre = h;
	int i = 0;
	
	while(pre->next) {
		i++;
		if(i == pos) {
			new = make_node(data);
			new->next = pre->next;
			pre->next = new;
		}
		pre = pre->next;
	}	
}

void del_node(Node *h, int pos)
{
	Node *pre, *del;	
	pre = h;
	int i = 0;
	while(pre->next) {
		i++;
		if(i == pos) {
			del = pre->next;
			pre->next = del->next;		
			free(del);
		}
		pre = pre->next;
	}
	
}

Node* reverse_list(int *arr, int len)
{
	int i;
	Node *newHead, *newPre;

	newHead = (Node *)malloc(sizeof(Node));
	newHead->data = 0;	
	newHead->next = NULL;

	newPre = newHead;

	for(i = 0; i<len; i++) {
		Node *node = (Node *)malloc(sizeof(Node));
		node->data = arr[i];	
		node->next = NULL;
		
		node->next = newHead->next;	
		newHead->next = node;
	}	
	return newHead;
}

void print_list(Node *h)
{
	printf("print the list \n");
	Node *cur = h->next;
	int idx = 0;
	while(cur) {
		printf("the %d value %d\n", ++idx, cur->data);	
		cur = cur->next;
	}
}

int main()
{
	Node *head, *newHead;	
	int arr[SIZE] = {11, 22, 333, 4444, 5};	
	head = init_list(arr, SIZE);
	print_list(head);
	printf("插入第一个个节点\n");
	insert_node(head, 1, 99);
	print_list(head);
	printf("删除第四个节点\n");
	del_node(head, 4);
	print_list(head);
}

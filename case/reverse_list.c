#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
//头插尾插初始化list

typedef struct Node_ {
	struct Node_ *next;
	int data;	
} Node;

Node* init_list(int *arr, int len)
{
	int i;
	Node *head, *pre;	

	head = (Node *)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;

	pre = head;
	for(i = 0; i<len; i++) {
		Node *node = (Node *)malloc(sizeof(Node));
		node->data = arr[i];	
		node->next = NULL;
		
		pre->next = node;
		pre = node;
	}	
	
	return head;
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
	newHead = reverse_list(arr, SIZE);
	print_list(newHead);	
}

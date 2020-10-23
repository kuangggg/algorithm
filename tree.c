#include <stdio.h>
#include <stdlib.h>

typedef struct Node_{
	struct Node_ *left;
	struct Node_ *right;
	int data;
}Node;

typedef struct Tree_{
	Node* root;
}Tree;

void create_node(Tree *t, int val)
{
	Node *new = (Node*)malloc(sizeof(Node));
	new->data = val;
	new->left = NULL;
	new->right = NULL;

	if(t->root == NULL) {
		t->root = new;		
	} else {
		Node *cur = t->root;	
		while(cur != NULL) {
			if(val < cur->data) {
				if(cur->left == NULL) {
					cur->left = new;	
					return;
				} else {
					cur = cur->left;	
				}
				
			} else {
				if(cur->right == NULL) {
					cur->right = new;	
					return;
				} else {
					cur = cur->right;
				}
			}
		}
	}
}

void print(Node *t)
{
	if(t != NULL) {
		printf("%d\n", t->data);
		print(t->left);	
		print(t->right);
	}
}

int main()
{
	Tree t;
	t.root = NULL;	
	int n;
	int i;
	scanf("%d", &n);

	for(i = 0; i< n; i++) {
		int tmp;
		scanf("%d", &tmp);
		create_node(&t, tmp);	
	}

	print(t.root);
	return 0;
}



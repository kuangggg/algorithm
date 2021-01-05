#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

struct BTreeNode {
	ElemType data;
	struct BTreeNode *left;
	struct BTreeNode *right;
};

void insert(struct BTreeNode **bst, ElemType x)
{
	if(*bst == NULL) {
		struct BTreeNode *p = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
		p->data = x;
		p->left = p->right = NULL;
		*bst = p;
	} else if(x < (*bst)->data) {
		insert(&((*bst)->left), x);	
	} else {
		insert(&((*bst)->right), x);	
	}
}

void createTree(struct BTreeNode **bst, ElemType a[], int n)
{
	int i;
	*bst = NULL;
	for(i = 0; i<n; i++)
		insert(bst, a[i]);
}

void p(struct BTreeNode* bt)
{
	if(bt != NULL) {
		p(bt->left);	
		printf("%d ", bt->data);
		p(bt->right);
	}
}

int main()
{
	int x, *px;
	ElemType a[10] = {30,50,20,40,25,70,54,23,80,92};
	struct BTreeNode *bst = NULL;

	createTree(&bst, a, 10);
	printf("init list\n");
	p(bst);

	printf("input insert value: ");
	scanf("%d", &x);
	insert(&bst, x);

	printf("after list\n");

	p(bst);
	
	return 0;
}

















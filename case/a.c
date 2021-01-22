#include <stdio.h>
#include <stdlib.h>

#define SIZE 12

//奇数在前偶数在后

void p(int *arr, int n);
void swap(int *a, int *b);

void main()
{
	int arr[SIZE] = {1, 3, 4, 5, 33, 22, 12, 34, 56, 77, 32, 55};

	p(arr, SIZE);

	int *front, *rear;

	front = arr;	
	rear = arr + SIZE - 1;
	exit(0);

	if(front != rear) {
		while((*front % 2) == 0) {
			while((*rear) % 2 == 1) {
				swap(front, rear);
			}
			rear--;
		}
		front++;
	}
	putchar('\n');

	p(arr, SIZE);
}

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void p(int *arr, int n)
{
	int i;
	for(i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

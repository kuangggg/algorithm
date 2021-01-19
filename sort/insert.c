#include <stdio.h>

#define SIZE 9

void print_sort(int *, int);

void main()
{
	int j, i;
	int k;

	int arr[SIZE] = {10, 5, 2, 4, 7, 1, 33, 22, 66};
	
	print_sort(arr, SIZE);
	
	for(j = 1; j < SIZE; j++) {
		k = arr[j];	
		i = j - 1;
		
		while(i >= 0 && arr[i] > k) {
			arr[i+1] = arr[i];	
			i--;
		}

		arr[i+1] = k;	
	}
	putchar('\n');
	print_sort(arr, SIZE);
	putchar('\n');
}

void print_sort(int *arr, int num)
{
	int i = 0;
	for(; i < num; i++) {
		printf("%d ", arr[i]);	
	}
}

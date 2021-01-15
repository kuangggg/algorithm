#include <stdio.h>

#define ARR_SIZE 10


int seq_search(int *, int n, int key);


int main()
{
	int arr[ARR_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 100};
	int idx;

	idx = seq_search(arr, ARR_SIZE, 4);	

	printf("the idx in array is :%d\n", idx);

	return 0;
}

int seq_search(int *arr, int n, int key)
{
	int i;
	for(i = 0; i < n; i++) {
		if(arr[i] == key) {
			return i;
		}	
	}
	
	return -1;
}

#include <stdio.h>

#define ARR_SIZE 11


int seq_search(int *, int n, int key);


int main()
{
	int arr[ARR_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 100, 300};
	int idx;

	idx = binary_search(arr, ARR_SIZE, 9);	
	printf("the idx in array is :%d\n", idx);

	idx = binary_search(arr, ARR_SIZE, 103);	
	printf("the idx in array is :%d\n", idx);

	return 0;
}

int binary_search(int *arr, int n, int key)
{
	int high, low, mid;
	
	low = 0;		
	high = n-1;

	while(low <= high) {
		mid = (high + low)/2;
		if(arr[mid] > key) {

			high = mid - 1;

		} else if (arr[mid] < key) {

			low = mid + 1;
		
		} else {
			return mid;	
		}
	
	}
	
	return -1;
}

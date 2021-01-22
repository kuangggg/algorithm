#include <stdlib.h>
#include <stdio.h>

void quick_sort(int *arr, int begin, int end)
{
	if(begin < end) {
		int tmp = arr[begin];	
		int i = begin;
		int j = end;
	
		while(i < j) {
			while(i<j && arr[j] > tmp) {
				j--;	
			}	
			arr[i] = arr[j];
			while(i<j && arr[i] <= tmp) {
				i++;	
			}
			arr[j] = arr[i];
		}
		arr[i] = tmp;
		quick_sort(arr, begin, i-1);
		quick_sort(arr, i+1, end);
	}
}

int main()
{
	int num[12] = {23,45,17,11,13,89,72,26,3,17,11,13};
	int n = 12, i;

	for(i = 0; i<n; i++) {
		printf("%d ", num[i]);	
	}

	quick_sort(num, 0, n-1);
	printf("sorted \n");
	for(i = 0; i<n; i++) {
		printf("%d ", num[i]);	
	}
	return 0;
}

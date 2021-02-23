#include <stdlib.h>
#include <stdio.h>
#define SIZE 12

void swap(int arr[], int l, int h);
int partition(int arr[], int l, int h);
void quick_sort(int *arr, int begin, int end);

//快速排序算法
void quick_sort(int *arr, int begin, int end)
{
	int pivot;

	if(begin < end) {
		pivot = partition(arr, begin, end);	

		quick_sort(arr, begin, pivot-1);
		quick_sort(arr, pivot+1, end);
	}
}

void swap(int arr[], int l, int h)
{
	int tmp;
	tmp = arr[l];
	arr[l] = arr[h];
	arr[h] = tmp;
}

int partition(int arr[], int l, int h)
{
	int pivot = arr[l];		
	
	while(l < h) {
		
		if(l < h && arr[h] >= pivot)
			h--;
		swap(arr, l, h);
		if(l < h && arr[l] <= pivot)
			l++;
		swap(arr, l, h);
	}
	return l;
}

int main()
{
	int num[SIZE] = {23,45,17,11,13,89,72,26,3,17,11,13};
	int n = SIZE, i;

	for(i = 0; i<n; i++) {
		printf("%d ", num[i]);	
	}
	putchar('\n');

	quick_sort(num, 0, SIZE-1);

	printf("quick sorted \n");
	for(i = 0; i<n; i++) {
		printf("%d ", num[i]);	
	}

	putchar('\n');
	return 0;
}

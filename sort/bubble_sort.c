#include <stdio.h>
#define ARRAY_SIZE 10

void print_arr(int *arr, int n);
void bubble_sort(int *arr, int n);

int main()
{
	int arr[ARRAY_SIZE] = {2, 1, 3, 4, 55, 6, 7, 8, 9, 10};

	print_arr(arr, ARRAY_SIZE);
	printf("\n");

	bubble_sort(arr, ARRAY_SIZE);

	print_arr(arr, ARRAY_SIZE);
	printf("\n");
	return 0;
}


void print_arr(int *arr, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

void bubble_sort(int *arr, int n)
{
	int i, j, tmp;
	int flag = 1;

	for(i = 0; (i < n-1) && (flag == 1); i++) {
	//	flag = 0;
		for(j = i+1; j < n; j++) {
			
			if(arr[i] > arr[j]) {
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;	

	//			flag = 1;
			}
		}
	}
}





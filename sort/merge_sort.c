#include <stdio.h>

#define LEN 12

int a[LEN] = {5, 2, 4, 7, 1, 3, 2, 6, 11, 32, 45, 66};

void merge(int begin, int middle, int end)
{
	int nl = middle + 1 - begin;
	int nr = end - middle;
	int left[nl], right[nr];
	int i, j, t;

	for(i = 0; i < nl; i++)
		left[i] = a[begin + i];

	for(j = 0; j < nr; j++)
		right[j] = a[middle + 1 + j];
	
	i = j = 0;	
	t = begin;

	while(i < nl && j < nr)
		if(left[i] < right[j])
			a[t++] = left[i++];
		else
			a[t++] = right[j++];
		
	while(i < nl)
		a[t++] = left[i++];

	while(j < nr)
		a[t++] = right[j++];
	
}

void sort(int begin, int end)
{
	int middle;
	if(begin < end) {
		middle = (begin + end) / 2;
			
		sort(begin, middle);
		sort(middle + 1, end);
		merge(begin, middle, end);
	}
}

print(int *arr, int n)
{
	int i;
	for(i = 0; i<n ; i++) {
		printf("%d ", arr[i]);	
	}
}

void main()
{
	sort(0, LEN - 1);
	print(a, LEN);
}

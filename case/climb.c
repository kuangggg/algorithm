#include <stdio.h>

//动态规划爬楼梯问题

int climb(int n)
{
	if(n < 1)
		return 0;
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
	
	int a = 1;
	int b = 2;
	//轮转
	int tmp = 0, i;

	for(i = 3; i < n; i++) {
		tmp = a + b;
		a = b;
		b = tmp;
	}
	
	return tmp;
}

int main()
{

	printf("%d\n", climb(10));	

	return 0;
	
}

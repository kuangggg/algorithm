#include <stdio.h>

int cir(int n, int m)
{
	int idx = 0, i;
	
	for(i = 2; i<= n; i++) {
		idx = (idx+m)%i;
	}

	return idx;
}

//约瑟夫环
int main()
{
	printf("%d\n", cir(11, 3));
}

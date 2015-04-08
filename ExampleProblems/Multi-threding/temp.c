#include <stdio.h>
int main()
{
	int a[2]= {3,4};
	int (*foo)(int, int)
	foo = sum;
	
}

int sum(int x, int y)
{
	return x+y;
}

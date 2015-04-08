#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int a[5];
	int *ptr = a;
	&a = (int *) malloc(sizeof(int) * 5);		// gives lvalue error;
	return 0;
}

/*
This Func demonstartes the simple usage of Func pointer;
Date : 9th April 14
*/
#include<stdio.h>

int add(int, int);
int main(void)
{
	int ret;
	int (*ptr)(int, int);	/* Declaration of a Function Pointer */
	ptr = add;
	ret = ptr(30, 40);
	printf("Result:[%d]\n", ret);
	return 0;
}

int add(int a, int b)
{
	return a+b;
}

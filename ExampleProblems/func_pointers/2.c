/*
This Program demonstartes how to pass function pointers as arguments to a Func;
Date : 9th April 14
*/

#include<stdio.h>

int add(int, int);
int multiply(int, int, int);

int main(void)
{
	int ret;
	int (*ptr)(int, int);			/* Declaration of a Function Pointer */
	ptr = add;
	ret = (*ptr)(30, 40);			/* Can also be written as "ret = ptr(30, 40);" */
	printf("Result:[%d]\n", ret);

	ret = multiply(ptr(5,5), 10, 10);	/* Expected answer is 1000; */
	printf("Result:[%d]\n", ret);
	
//	printf("Addr of Function Ptr:[%d]\n", ptr);
	return 0;
}

int add(int a, int b)
{
	return a+b;
}

int multiply(int a, int b, int c)
{
	return a*b*c;
}

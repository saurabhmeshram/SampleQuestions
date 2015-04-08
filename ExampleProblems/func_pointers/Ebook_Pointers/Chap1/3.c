/*
The Following Programs explain the following
1. Pointer to an Integer Constant 		: const int *ptr == int const *ptr
2. Constant Pointer to an Integer		: int *const ptr 
3. Constant Pointer to an Constant Integer	: const int *const ptr 

All the errors will be at Compile-time.
*/

#include <stdio.h>

#ifdef Q1
/* Pointer to an Integer Constant */
int main(void)
{
	int a = 10;
	const int *ptr = a;		// Can also be written as "int const *ptr"
	int const *tmp = a;
	*ptr = 20;
	*tmp = 30;
	return 0;
}
#endif

#ifdef Q2
/* Constant Pointer to an Integer */
int main(void)
{
	int a = 10, b = 20;
	int *const ptr = a;
	ptr = &b;
	return 0;
}
#endif

#ifdef Q3
/* Constant Pointer to an Constant Integer */
int main(void)
{
	int a = 10, b = 20;
	const int *const ptr = &a;
	*ptr = 20;
	ptr = &b;
	return 0;
}
#endif

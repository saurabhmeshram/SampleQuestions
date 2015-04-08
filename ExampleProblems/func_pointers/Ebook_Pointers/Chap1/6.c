/* Demonstartes Pointer Arithematic Operations */
#include <stdio.h>

#ifdef Q1
/* Accessing Array out of Bounds */
int main(void)	
{
	int arr[] = {10, 20, 30};
	int *ptr = arr;

	printf("[%d]\t", *ptr);		// Prints 10
	ptr++;

	printf("[%d]\t", *ptr);		// Prints 20
	ptr++;

	printf("[%d]\t", *ptr);		// Prints 30
	ptr++;

	printf("[%d]\t", *ptr);		// Accessing Memory out of bounds, it is allowed and has undefined behavior.
	ptr++;

	printf("\n");
	return 0;
}
#endif

#ifdef Q2
/* Illustrates Inc of pointer wrt to data-types */
int main(void)
{
	char c, *pc;
	short s, *ps;
	pc = &c;
	ps = &s;
	printf("Before : Addr of pc[%u]\n", (unsigned int) pc );
	printf("Before : Addr of ps[%u]\n\n", ps );

	++ps;
	++pc;

	printf("After : Addr of pc[%u]\n", pc );		// Inc only once since sizof(char) = 1
	printf("After : Addr of ps[%u]\n", ps );		// Inc only once since sizof(short) = 2
	return 0;
}
#endif


#ifdef Q3
/* Trying to inc void pointer 
Ref: http://gcc.gnu.org/onlinedocs/gcc-4.8.0/gcc/Pointer-Arith.html */
int main(void)
{
	void *pv;
	printf("Before : Addr of pv[%u]\n", (unsigned int) pv );
	pv += 1;
	printf("Before : Addr of pv[%u]\n", (unsigned int) pv );
	/* The above value is inc by one, since sizeof(void) is one */

	printf("Sizeof void[%d]\n", sizeof(void));
	return 0;
}
#endif

/* 
Compile the Below Program by using Macros for Question No. 
Example (to compile question1 use Q1) : gcc -o exe -Wall -DQ1

The Following Programs are designed to result into SIGSEGV or Memory Leak.
*/

#include <stdio.h>
#include <stdlib.h>

#ifdef Q1
/* Program which deferences NULL - Simplest Program to Generate SIGSEGV */
int main(void)
{
	int *ptr = NULL;
	printf("[%d]\n", *ptr);			// Gives SIGSEGV
	return 0;
}
#endif

#ifdef Q2
/* Program which tries to dereference automatic variable */
int *ptr = NULL;
int main()
{
	printf("%d\n", *ptr);
	return 0;
}

void helloo(void)
{
	int x = 10;
	ptr = &x;
}
#endif

#ifdef Q3
/* Trying to Access Heap Allocated mem after being freed */
int main(void)
{
	typedef struct foo {
		int a;
		char b;
	}foo_t;
	
	foo_t *ptr = NULL;
	ptr->a = 10;
	 
	//printf("[%d]\n", ptr->a);			// This should also result in SIGSEGV (Accessing before Mem is allocated).
	//return 0;
	ptr = (foo_t *) malloc(sizeof(struct foo));
	free(ptr);
	
	printf("[%d]\n", ptr->a);
	return 0;
}
#endif

#ifdef Q4
/* Trying to Derefernece the Value of a Freed Ptr, gives SIGSEGV */
int main()
{
	int *ptr = NULL;
	*ptr = 10;
	return 0;
}
#endif

#ifdef Q5
/* Trying to write to a Readonly Memory */
int main()
{
	printf("Question 5.\n");
	char a[5];
	a[6] = 'z';
	return 0;
}
#endif

/* Illustrate Dangling Pointers */
/* To Avoid a Dangling pointer, always assign it to NULL, after freeing */
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int *ptr = (int *) malloc(sizeof(int));
	int num = 5;

	ptr = &num;
	printf("Addr of ptr[%p]\tValue:[%d]\n", ptr, *ptr);
	free(ptr);

	/* Trying to assign val to the freed addr, Results in double free */
	*ptr = 10;
	return 0;
}

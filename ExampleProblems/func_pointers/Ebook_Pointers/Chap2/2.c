/* Illustrate Double Free Error */

#include <stdio.h>
#include <stdlib.h>

#ifdef Q1
int main (void)
{
	int *ptr = (int *) malloc(sizeof(int) * 4);
	free(ptr);

	/* Trying to free it again, results in double free error */
	free(ptr);
	return 0;
}
#endif

#ifdef Q2
int main (void)
{
	int *ptr = (int *) malloc(sizeof(int) * 4);
	
	int *tmp = ptr;

	free(ptr);

	/* Indirectly freeing twice - results in double free error */
	free(tmp);
	return 0;
}
#endif

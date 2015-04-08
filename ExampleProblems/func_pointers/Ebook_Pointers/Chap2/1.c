#include <stdio.h>
#include <stdlib.h>

#ifdef Q1
int *glob_ptr;
int main (void)
{
	glob_ptr = (int *) malloc(sizeof(int) * 4);
	if(glob_ptr == NULL)
		printf("Malloc Failed\n");
	return 0;
}
#endif

#ifdef Q2
/* Malloc will always fail for a Static Variable */
int main (void)
{
        static int *stat_ptr = (int *) malloc(sizeof(int) * 4);
        return 0;
}
#endif

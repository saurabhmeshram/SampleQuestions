#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int row=3, col=3;
    int i,j;
    int **arr = NULL;

    arr = (int **) malloc (sizeof(int)*row);
    if (!arr)
	printf("Malloc Failure\n");

    for(i=0; i<row;i i++) {
	for(j=0; j<col; j++) {
	    printf("Val of arr[%d][%d]: [%d]\n", i, j, *(*(arr + i) + j));
	}
    }

    /*    printf("Alements of Array are:");
	  for(i=0;i<row;i++) {
	  for(j=0;j<col;j++) {
     *(*(arr + i) + j) = 10;
     }
     }
     */
    return 0;
}

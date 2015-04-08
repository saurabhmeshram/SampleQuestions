#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

int **get_arr(int **arr, int row, int col);
void disp_arr(int **arr, int row, int col);

int main (void)
{
    int row, col;
    int **arr = NULL;
    printf("Enter rows:");
    scanf("%d", &row);
    __fpurge(stdin);
    printf("Enter Cols:");
    scanf("%d", &col);
    __fpurge(stdin);

    /* Allocate Memory for the Array */
    arr = (int **) malloc (sizeof(int) * row);
    if (!arr)
	printf("Malloc Failed\n");

    int i;
    for(i=0; i<row; i++) {
	*(arr+i) = (int *) malloc (sizeof(int) * col);
	if (!(arr +i))
	    printf("Malloc Failed\n");

    }

    arr = get_arr(arr, row, col);
    disp_arr(arr, row, col);
    return 0;
}

int **get_arr(int **arr, int row, int col)
{
    printf("Enter the Array Elements:");
    int i,j;
    for(i=0; i<row; i++) {
	for(j=0; j<col; j++) {
	    //			(*(*(arr + row) + col)) = 1;
	    arr[row][col] =1;
	}
    }
    return arr;
}

void disp_arr(int **arr, int row, int col)
{
    printf("Array Elements are:\n");
    int i,j;
    for(i=0; i<row; i++) {
	for(j=0; j<col; j++) {
	    //printf("%d ", arr[row][col]);
	    printf("%d", *(*(arr + row) + col));
	}
    }
    putchar(10);
    return;
}

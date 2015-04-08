#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
	int row, col;
	
	printf("Enter No of Rows: ");
	scanf("%d", &row);
	printf("Enter No of Coloums: ");
	scanf("%d", &col);
	int arr1[row][col];
	int arr2[row][col];

	arr1 = get_arr(arr1, row, col);
	print_arr(arr1, row, col);

	arr2 = get_arr(arr2, row, col);
	print_arr(arr2, row, col);
	return 0;
}

void print_arr(int arr[][], int row, int col)
{
	printf("Elements of the Array are\n");
	int i, j;
	for (i=0; i<row; i++) {
		for (j=0; j<col; j++) {
			printf("%d\n", (arr[row][col]));
		}
		printf("\n");
	}
	return;
}

int **get_arr(int arr[][], int row, int col)
{
	printf("Enter the Array Elements: ");
	int i, j;
	for (i=0; i<row; i++) {
		for (j=0; i<col; j++) {
			scanf("%d\n", &(arr[row][col]));
		}
	}
	return arr;
}

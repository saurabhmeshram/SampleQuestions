#include <stdio.h>
#define row 2
#define col 3
int main()
{
	int arr[row][col] = {1,2,3,4,5,6};
	int i,j;
	for (i=0; i<row; i++) {
		for (j=0; j<col; j++) {
			printf("Addr of %d: [%u]\n", (int) arr[i][j], (unsigned int) &(arr[i][j]));
		}	
	}
	printf("Val of arr[2][1]: [%d]\n", );
	return 0;
}

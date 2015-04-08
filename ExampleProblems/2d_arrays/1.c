#include <stdio.h>
#define SIZE 2
int main (void)
{
	int i, j, arr[SIZE][SIZE] = {4,3,2,1};
	printf("_______________________________________________________\n");
	printf("Address of the Elements\n");
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			printf("[%d]:[%u]\n", arr[i][j], (unsigned int) &(arr[i][j]));
		}
	}
	printf("_______________________________________________________\n");
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			printf("arr[%d][%d]:	[%u]\n", i, j, (unsigned int) *((*(arr +i)) + j));
		}
	}
	printf("_______________________________________________________\n");

	i=1;j=1;
	printf("When i=%d,j=%d\n", i, j);
	printf("(arr)		: [%u]\n", (arr));
	printf("(arr+i)		: [%u]\n", (arr+i));
	printf("*(arr+i)	: [%u]\n", *(arr+i));
	printf("(*(arr+i)+j)	: [%u]\n", (*(arr+i)+j));
	printf("*(*(arr+i)+j)	: [%u]\n", *(*(arr+i)+j));
	return 0;
}

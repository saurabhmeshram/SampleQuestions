#include <stdio.h>
#define ROW 3
#define COL 4
int main (void)
{
	int i, j, arr[ROW][COL] = {1,2,3,4,5,6,7,8,9,10,11,12};
	printf("_______________________________________________________\n");
	printf("Address of the Elements\n");
	for(i=0; i<ROW; i++) {
		for(j=0; j<COL; j++) {
			printf("[%d]:[%u]\n", arr[i][j], (unsigned int) &(arr[i][j]));
		}
	}
	printf("_______________________________________________________\n");
	for(i=0; i<COL; i++) {
		for(j=0; j<ROW; j++) {
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

#include <stdio.h>
/* Understnading the Memory layout for a 2D/3D Array */
#ifdef Q1
int main(void)
{
	char a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int i, j;
	
	/* print all addr */
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) 
			printf("[%u]\t", (unsigned int) &(a[i][j])); 		// Can also be written as ((a + i) +j)
	}
	printf("\n");
	return 0;
}
#endif

#ifdef Q2
int main(void)
{
	char a[2][2][2] = {{{0}}};		// Can be written as {0}, but compiler gives warning
	int i, j , k;
	
	/* print all addr */
	for(i=0; i<2; i++) {
		for(j=0; j<2; j++) {
			for(k=0; k<2; k++) {
				printf("[%d,%d,%d][%u]\t", \ 
				i,j,k, (unsigned int) &(a[i][j][k]));	// Can also be written as (((a + i) +j) +k)
			}
		}
	}
	printf("\n");
	return 0;
}
#endif

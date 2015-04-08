#include <stdio.h>
int main (void)
{
    int i, j, row, col;

    printf("Enter The row lenght\n");
    scanf("%d", &row);

    for (i=0; i<row; i++) {
	for (j=0; j<i; j++) {
	    printf("[*]");
	}
	printf("\n");
    }
    return 0;
}

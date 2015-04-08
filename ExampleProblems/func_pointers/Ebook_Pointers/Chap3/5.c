#include<stdio.h>
void foo (int **val);
int main()
{
	int *ptr = NULL;
	printf("Val of ptr : [%u]\n", ptr);
	printf("Val of &ptr : [%u]\n", &ptr);
	foo(&ptr);
	if (ptr != NULL) {
		printf("Addr of ptr[%u]\n", ptr);
		printf("Val at ptr[%d]\n", *ptr);
	}
	return 0;
}

void foo (int **val)
{
	printf("Addr of Val[%u]\n", val);
	*val = 2005;
	return;
}

#include <stdio.h>
#include <stdlib.h>

#define VAL 5
#define SIZE 10

#ifdef Q1
int* allocate_array(int size, int val)
{
	int i, *ptr = (int *)malloc(size * sizeof(int));
	printf("Addr of ptr:[%p]\n\n", ptr);
	for(i=0; i<size; i++) { 
		*(ptr+i)  = i;
		printf("[%u]\t", (ptr+i));
	}
	printf("\n");
	return ptr;
}
int main(void)
{
	int i, *arr = allocate_array(SIZE, VAL);
	for(i=0; i<SIZE; i++)
		printf("[%d][%u]\t", *(arr+i), (arr + i));
	printf("\n");
	return 0;
}
#endif

#ifdef Q2
/* Here we are trying to return a local variable in allocate_array Function */
int* allocate_array(int size)
{
	int i, arr[SIZE];
	for(i=0; i<size; i++) 
		arr[i]  = i;
	printf("\n");
	return arr;					/* Trying to return local var */
}
int main(void)
{
	int i; 
	int *arr = allocate_array(SIZE);
	for(i=0; i<SIZE; i++)
		printf("[%d]\t", arr[i]);
	printf("\n");
	return 0;
}
#endif

#ifdef Q3
int* allocate_array(int *ptr, int size)
{
	int i;
	if (ptr != NULL) {
		for(i=0; i<size; i++) 
		    *(ptr + i)  = i;
	}
	printf("\n");
	return ptr;					/* Trying to return local var */
}
int main(void)
{
	int i; 
	int *arr = (int *) malloc(2 * sizeof(int)); 
	arr = allocate_array(arr, SIZE);
	for(i=0; i<SIZE; i++)
		printf("[%d]\t", *(arr+i));
	printf("\n");
	return 0;
}
#endif

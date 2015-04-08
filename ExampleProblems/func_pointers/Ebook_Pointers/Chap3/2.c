#include <stdio.h>
#define PRINT_VAL(a, b) 	printf("Val of a[%d]\tb[%d]\n", a,b)

#ifdef Q1
void swap_by_value(int a, int b)
{
	int temp =a;
	a = b;
	b = temp;
	return;
}
int main (void)
{
	int a =10, b=20;
	printf("Swap by Value\n");
	PRINT_VAL(a, b);
	swap_by_value(a, b);
	PRINT_VAL(a, b);
	return 0;	
}
#endif

#ifdef Q2
void swap_by_addr(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}
int main (void)
{
	int a =10, b=20;
	printf("Swap by Address\n");
	PRINT_VAL(a, b);
	swap_by_addr(&a, &b);
	PRINT_VAL(a, b);
	return 0;	
}
#endif

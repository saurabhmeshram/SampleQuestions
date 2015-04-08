#include <stdio.h>
#define X printf("[%d]\n", a)
void abc(int a, int b)
{
	X;
	printf("%d,%d\n",++a,++b);
	X;
}
void main()
{
	int a=10;
	X;
	abc(++a,a++);
	X;
	abc(a++,++a);
	X;
	printf("%d\n",a);
}


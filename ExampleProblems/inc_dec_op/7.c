#include<stdio.h>
extern int a=5;
int main()
{
	void fun();
	printf("\n a=%d",a);
	fun();
	return 0;
}

int a;
void fun()
{
	printf("\n in fun a=%d",a);
}

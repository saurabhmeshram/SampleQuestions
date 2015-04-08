#include<stdio.h>
#define X printf("X=[%d]\n", x)
#define Y printf("Y=[%d]\n", y)
int main()
{
	int x=20, y=35;
	x = ++x + y;
	X;
	Y;	
printf("===%d\n",x = x++ + y);
	X;
	Y;	

printf("%d%d%d\n",50,100);
}

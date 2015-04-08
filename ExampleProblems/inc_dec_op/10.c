#include<stdio.h>
#define swap(a,b) a=a+b;b=a-b;a=a-b;
void main()
{ 
	int x=5, y=10; 
	swap (x,y); 
	printf("%d %d\n",x,y); 
	swap2(x,y);		// No Swapping is actually happening. 
	printf("%d %d\n",x,y); 
}
int swap2(int a, int b) 
{ 
	int temp; 
	temp=a; 
	b=a; 
	a=temp; 
	return 0;
}

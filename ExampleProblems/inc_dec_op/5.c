#include <stdio.h>
int main()
{
	int i;
	for(i=0;i<5;i++)
	{
		static int a=0;
		int b=0;
		a++;
		b++;
		printf("%d  %d\n",a,b);
	}
	return 0;
}

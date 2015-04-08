#include <stdio.h>
int main()
{
	int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	printf("a :: %u\n",a);
	printf("a[0] :: %u\n",a[0]);
	printf("a+0 :: %u\n",a+0);
	printf("a[2] :: %u\n",a[2]);
	printf("a[0][0] :: %u\n",a[0][0]);
	printf("a[2][3] :: %u\n",a[2][3]);

}

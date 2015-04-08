#include<stdio.h>
int check(int a)
{
	return (a & 01)?printf("ODD\n"):printf("EVEN\n");
}

int main()
{
	int val;
	printf("Enter Val:");
	scanf("%d", &val);
	int ret = check(val);
/*	if(1 == ret)
		printf("ODD\n");
	else
		printf("EVEN\n");
*/
	return 0;
}

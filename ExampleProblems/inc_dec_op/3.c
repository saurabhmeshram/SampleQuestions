#include<stdio.h>
void main()
{
	int i;
	i=2;
pskills:
	printf("%d ",i);
	i=i+2;
	if(i<=20)
		goto pskills;

	printf("***\n%c\n***","Pskills"[4]);	//Printf 'l'
}

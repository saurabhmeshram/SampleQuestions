#include<stdio.h>
int main(){
	static int s;
	++s;
	printf("%d\n",s);
	if(s<=3)
		main();
	printf("%d",s);
	return 0;
}

#include <stdio.h>
extern int a;
void fun();

main(){
	printf("\n a=%d",a);
	fun();
	return 0;
}
int a=7;
void fun(){
	printf("\n in fun a=%d",a);
}

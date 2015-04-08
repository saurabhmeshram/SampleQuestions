/*
STACK OVERFLOW LEADING TO SIGSEGV
Here we Recursivley Calling main(), until stack is exhausted.
This exhausteion is stack will result it to access memory outside the reserved area.
SIGSEGV will be generated for Memory Protection.

Try runnin the program by setting stack size to some lower value.
$ ulimit -s <Some Small Value>	

Ref: http://stackoverflow.com/questions/2685413/what-is-the-difference-between-a-segmentation-fault-and-a-stack-overflow/2685434#2685434
*/

#include<stdio.h>
int main(void)
{
	printf("Hello\n");
	main();
	return 0;
}

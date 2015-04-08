/* Shows Valid/Invalid Pointer Assignement */
/* Statment 3,4 is valid and results in no compilation error, will result in Runtime error, when derefernced */

#include <stdio.h>
int main(void)
{
	int *ptr;
	int num = 10;
	ptr = 0;		// Valid Expression.
	ptr = NULL;		// Valid Expression.
	ptr = 100;		// Statement 3.
	ptr = num;		// Statement 4.
	return 0;
}

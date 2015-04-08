/* Shows Differnece between NULL and Integer Zero */

#include <stdio.h>
int main(void)	
{
	int *ptr = 0;		// Zero refers to NULL pointer.
	int num;
	ptr = &num;
	*ptr = 0;		// Zero refers to actual integer 0.
	return 0;
}

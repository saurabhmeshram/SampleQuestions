/********************************************************************
 *                	digit() To check , for the digit            *
 ********************************************************************/
#include	"header.h"
int digit( char *str )
{
	if (*str < 48 || *str > 57)
		return 0;
	else
		return 1;
}

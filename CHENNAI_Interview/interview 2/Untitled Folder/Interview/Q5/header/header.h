/********************************************************************
 *                               HEADER				    *
 ********************************************************************/
#ifndef		__HEADER
#define		__HEADER

#include	<stdio.h>
#include	<stdio_ext.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<dirent.h>
#include	<errno.h>
#include	<unistd.h>

#define	SIZE 1024
#define	SIZE1 50
struct option {
	unsigned int aflag : 1;
	unsigned int eflag : 1;
	unsigned int Tflag : 1;
	unsigned int lflag : 1;
};

/**Prototype to perform ps command*/
void my_ps( struct option *flag, int argc );

/**Prototype to check digit */
int digit( char *str );

#endif

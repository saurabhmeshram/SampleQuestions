#ifndef __DEBUG_HEADER__
#define __DEBUG_HEADER__

#define LOG_FILE "log.txt"
#define FILE_PERMISSION 0666

/* Change Configuration here
1 for Enable 
0 for Disable */
#define AT_DEBUG	1

#if AT_DEBUG == 1
#define DEBUG	1 
#else
#define DEBUG	0
#endif

#define debug_print	DEBUG_PRINTF
#define DEBUG_PRINTF(fd, fmt, ...)							\
	do {										\
		if(DEBUG)								\
			fprintf(fd, "[%s]:[%d] " fmt, __func__, __LINE__, __VA_ARGS__);	\
	} while(0)

#endif

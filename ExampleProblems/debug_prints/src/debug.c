/*
Description: Utility for Enabling or Disabling Debug Printfs.
Date: May 26th 2014
*/

#include "common.h"
#include "debug.h"

int main (void)
{

	int fd = INVALID;
	int errno;
	FILE *fp = NULL;
	fd = open(LOG_FILE, O_WRONLY | O_CREAT, FILE_PERMISSION);

	if(INVALID == fd) {
		debug_print(stderr, "%s\n", "Error in Opening Log File");
		exit(EXIT_FAILURE);
	}
	fp = fdopen(fd, "w");

	fprintf(stderr, "[%s]:[%d] %s\n", __func__, 44, "Testing Normally");
	fprintf(fp, "[%s]:[%d] ""Hello\n", __func__, 44);

	debug_print(fp, "%s\n", "Testing Normally");
	//debug_printf("Debug Testing\n");	<== Cannot be written like this, not compaitable with the above macro.
	debug_print(fd, "%s\n", "Debug Testing");
	debug_print(fd, "Debug Testing with Value: %d\n", 5);
	return 0;
}

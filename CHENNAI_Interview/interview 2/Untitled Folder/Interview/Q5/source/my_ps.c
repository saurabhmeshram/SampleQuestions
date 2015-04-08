/************************************************************************
 *    my_psp() To implement ps command with (-P, -s, -t, -l) options    *
 ************************************************************************/

#include	"header.h"

void my_ps( struct option *flag, int argc )
{
	__fpurge(stdin);
	int i = 0;		/**Store index value for loop*/
	int fd = 0;		/**Store file descriptor value for loop*/
	char *path = NULL;	/**Store proc file path*/
	char *newpath = NULL;	/**Store new path*/
	char *cpath = NULL;     /**Store the current process path*/
	char *buff = NULL;	/**Store the read content*/
	char *buff1 = NULL;	/**Store the read content of current process*/
	char *tokens[20];	/**Store tokens */
	struct dirent **namelist;
	int n = 0;		/**Store return value of scandir*/
	int temp = 0;		/**temprory variable */
	int j = 0;		/**store value*/
	char *tok[10];		/**store current running process tokens*/
	char ttyval[10];	/**store tty value*/
	int tmval, tmhw, tmmin, tmsec;	/**store time hr, min & sec*/
	char *statm[1];		/**store statm tokens*/
	char *buff2 = NULL;	/**store information of statm */
	char *buff3 = NULL;	/**Store information of wchan*/
	char *spath = NULL;	/**store statm path*/
	char *wpath = NULL;	/**store wchan path*/
	
	/*************************MEMORY ALLOCATION**********************/

	if ( !(path = (char *)malloc(sizeof(char) * SIZE1)) ) {
		printf("\nMalloc Failed!\n");
		exit(1);
	}

	if ( !(cpath = (char *)malloc(sizeof(char) * SIZE1)) ) {
		printf("\nMalloc Failed!\n");
		exit(1);
	}
	if ( !(spath = (char *)malloc(sizeof(char) * SIZE1)) ) {
		printf("\nMalloc Failed!\n");
		exit(1);
	}
	if ( !(wpath = (char *)malloc(sizeof(char) * SIZE1)) ) {
		printf("\nMalloc Failed!\n");
		exit(1);
	}
	if ( !(newpath = (char *)malloc(sizeof(char) * SIZE1)) ) {
		printf("\nMalloc Failed!\n");
		exit(1);
	}
	if ( !(buff = (char *)malloc(sizeof(char) * SIZE)) ) {
		printf("\nMalloc Failed!\n");
		exit(1);
	}
	if ( !(buff2 = (char *)malloc(sizeof(char) * SIZE)) ) {
		printf("\nMalloc Failed!\n");
		exit(1);
	}
	if ( !(buff3 = (char *)malloc(sizeof(char) * SIZE)) ) {
		printf("\nMalloc Failed!\n");
		exit(1);
	}
	if ( !(buff1 = (char *)malloc(sizeof(char) * SIZE)) ) {
		printf("\nMalloc Failed!\n");
		exit(1);
	}

	/***************************scandir*************************/
	sprintf(path, "%s", "/proc");
	if ((n = scandir(path, &namelist, 0, 0)) == -1) {
		printf("Scandir_Error: %d\n", errno);
		exit(1);
	}

	bzero(cpath, SIZE1);
	sprintf(cpath, "%s/%d/stat", path, getpid() );
	if ((fd = open(cpath, O_RDONLY)) == -1) {
		printf("Open2_Error: %d\n", errno);
		exit(1);
	}
	bzero(buff1, SIZE);
	if (read(fd, buff1, SIZE) == -1) {
		printf("Read_Error: %d\n", errno);
		exit(1);
	}
	tok[0] = strtok(buff1, " \n");
	for ( j = 1; j < 8 ; j++) 
		tok[j] = strtok(NULL, " \n");

	close(fd);

	/*************************DISPLAY COLUMN NAME*****************/
	if (flag -> lflag) 
		printf("%s %s  %s  ", "F", "S", "UID");
	
	printf("%5s  ", "PID");
	
	if (flag -> Tflag) 
		printf("%s  ", "SPID");

	if (flag -> lflag) 
		printf("%s  %s  %s %s %s  %s  %s  ", "PPID", "C", "PRI", "NI", "ADDR", "SZ", "WCHAN");
	
	printf("%5s%8s      %4s\n", "TTY", "TIME", "CMD");


	/***************PERFORMING OPERATIONS FOR EACH DIRECTORY VALUE*******/
	for (i = 0; i < n; i++) {
		__fpurge(stdin);

		/**In proc file, if digit found then proceed 
		 * otherwise continue
		 */
		if ( (namelist[i]-> d_name[0] == '.') || (!digit(namelist[i] -> d_name)) )
			continue;
		sprintf(newpath, "%s/%s/stat", path, namelist[i] -> d_name);
		sprintf(spath, "%s/%s/statm", path, namelist[i] -> d_name);
		sprintf(wpath, "%s/%s/wchan", path, namelist[i] -> d_name);

		/**Open the proc file , which start from digit*/
		if ((fd = open(newpath, O_RDONLY)) == -1) {
			printf("Open_Error: %d\n", errno);
			exit(1);
		}
		bzero(buff, SIZE);

		/**Read that process into a buffer*/
		if (read(fd, buff, SIZE) == -1) {
			printf("Read_Error: %d\n", errno);
			exit(1);
		}
		close(fd);

		/**Convert proc process data into tokens*/
		tokens[0] = strtok(buff, " \n");
		for (j = 1; j < 20; j++)
			tokens[j] = strtok(NULL, " \n");
		
		/*************statm***********************/
		if ((fd = open(spath, O_RDONLY)) == -1) {
			printf("Open_Error: %d\n", errno);
			exit(1);
		}
		bzero(buff2, SIZE);

		/**Read that process into a buffer*/
		if (read(fd, buff2, SIZE) == -1) {
			printf("Read_Error: %d\n", errno);
			exit(1);
		}
		close(fd);
		statm[0] = strtok(buff2, " \n");
		/**************wchan*************/
		
		if ((fd = open(wpath, O_RDONLY)) == -1) {
			printf("Open_Error: %d\n", errno);
			exit(1);
		}
		bzero(buff3, SIZE);

		/**Read that process into a buffer*/
		if (read(fd, buff3, SIZE) == -1) {
			printf("Read_Error: %d\n", errno);
			exit(1);
		}
		close(fd);	
		buff3[7] = '\0';
		
		/************TTY******************/
		bzero(ttyval, 10);
		temp = atoi(tokens[6]);

		if ( temp >= 34816 ) 
			sprintf(ttyval, "%s%d", "pts/", temp - 34816);
		else if (temp >= 1024 ) 
			sprintf(ttyval, "%s%d", "tty", (temp - 1024));
		else
			sprintf(ttyval, "%s", "?");
		
		/*********************TIME*******************************/
		tmval = (atoi(tokens[13]) + atoi(tokens[14])) / 100;
		tmhw = (tmval / (60 * 60));
		tmmin = (tmval % (60 * 60)) / 60;
		tmsec =  (tmval % (60 * 60)) % 60;
		
		/**************PERFORMING OPERATION BASED ON FLAGS************/
		if (flag -> aflag && (!flag -> eflag)) {
			if ( temp < 34816 || (!strcmp(tokens[1], "(bash)")) )
					continue;
		}

		if (flag -> lflag || flag -> Tflag || flag -> aflag || flag -> eflag) {
			if ( strcmp(tok[6], tokens[6]) && (!flag -> aflag) && (!flag -> eflag)) 
				continue;
			else {
				if (flag -> lflag)
					printf("%d %s  %d  ", 0, tokens[2], getuid());
				printf("%5s ", tokens[0]);
				if (flag -> Tflag) {
					printf("%5s ", tokens[5]);

				}
				if (flag -> lflag)
					printf("%5s%2d%4d%5s%2c %5s  %7s  ", tokens[3], 0, \
					atoi(tokens[17]) + 60, tokens[18], '-', statm[0], buff3);

				tokens[1] = strtok(tokens[1], "()");
				printf("%5s %.2u:%.2u:%.2u  %4s\n", 
					ttyval, tmhw, tmmin, tmsec, tokens[1]);
			}

		}
		
		/******************DEFAULT CASE***************/
		if (argc == 1) {
			if ( strcmp(tok[6], tokens[6]) ) 
				continue;
			else {
				tokens[1] = strtok(tokens[1], "()");
				printf("%5s %5s\t%d:%d:%d %7s\n", 
					tokens[0], ttyval, tmhw, tmmin, tmsec, tokens[1]);
			}
		}
	}
}

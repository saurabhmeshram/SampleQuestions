/********************************************************************
 *               main() for pgrep with (-P, -l, -s, -t) options     *
 ********************************************************************/

#include	"header.h"

int main ( int argc, char *argv[] )
{
	int opt = 0;
	struct option flg = { 0, 0, 0, 0 };

	while ((opt = getopt(argc, argv, "aeTl")) != -1) {
		switch ( opt ) {
			
		case 'a':
			flg.aflag = 1;	
			break;

		case 'e':
			flg.eflag = 1;
			break;

		case 'T':
			flg.Tflag = 1;
			break;

		case 'l':
			flg.lflag = 1;
			break;
		default:
			printf("Usage: Invalid options\n");
			exit(1);
		}
	}

//	if (argv[optind] != NULL) {
//		my_ps( argv[optind], &flg, argc);
//	}
	my_ps( &flg, argc );

	return 0;
}

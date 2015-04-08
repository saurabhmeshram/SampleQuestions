#include <stdio.h>
int main()
{
	struct s
	{
		char a;
		char b;
	}A;


	struct info{
		char ch;
		int a;
		short int b;
	} B;

	struct abc {
		int a;
		int c;
		struct abc *ptr;
		char b;
		int d:3;
	} C; 
	printf("Size A: [%d]\n", sizeof(A));
	printf("Size B: [%d]\n", sizeof(B));
	printf("Size c: [%d]\n", sizeof(C));
	return 0;
}

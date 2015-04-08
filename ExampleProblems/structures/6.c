#include <stdio.h>
#if 0
union un_t {
	struct st_t {
		unsigned int a:4;
		unsigned int b:4;
	}st;
	char c;
};
#endif


int main()
{
	int a = 69;
	printf("[%p]\n", a);
	return 0;
}

#include <stdio.h>

union un_t {
	struct st_t {
		unsigned int a:4;
		unsigned int b:4;
	}st;
	char c;
};

int main()
{
	union un_t un;
	un.c = 0x45;

	printf("[%d]\n", un.st.a);
	printf("[%d]\n", un.st.b);
	return 0;
}

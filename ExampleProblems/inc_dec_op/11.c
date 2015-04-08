#include <stdio.h>
int main(void)
{
	auto a;
	register r;
	static s;
	extern e;
	printf("%d",sizeof a);
	printf("%d",sizeof r);
	printf("%d",sizeof s);
	printf("%d",sizeof e);
	return 0;	
}

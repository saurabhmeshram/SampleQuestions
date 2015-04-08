#include <stdio.h>
int foo(int local_foo);
int main(void)
{
	int local_main = 0;
	int (*ptr)(int) = foo;			// Func Pointer holding foo's Addr
	int ret = foo(local_main);

	printf("[Main] Addr of local var\t:[%u]\n", &local_main);
	printf("Addr of Func called\t:[%u]\n", ptr);
	return 0;
}

int foo(int local_foo)
{
	int local_foo2;
	printf("Addr of local param\t:[%u]\n", &local_foo);
	printf("[Foo] Addr of local var\t:[%u]\n\n", &local_foo2);
	return local_foo2;
}

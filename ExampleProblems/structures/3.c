#include <stdio.h>
struct outer  {
	int a;
	int *p;
};

int foo(struct outer **);

int main()
{
	struct outer *op = NULL;
	foo(&op);
	printf("%d\n", op->a );
	return 0;
}

int foo(struct outer **p)
{
	int a = 10;
	int b = 20;
	(*p)->a = a;
//	p->p = &b;
	return 0;
}

#include <stdio.h>
typedef struct tmp {
    int a;
    int c[3];
} tmp_t;

int main()
{
	tmp_t var1, var2, *varp;
	int i;
	var1.a =10;
	for (i=0;i<3;i++)
		var1.c[i] = i;

	printf("var1:[%d]\n", var1.a);
	printf("var1:[%d]\n", var1.c[1]);
	
	varp = &var1;
	printf("varp:[%d]\n", varp->a);
	printf("varp:[%d]\n", varp->c[1]);

	var2.a = (varp->a);
	for (i=0;i<3;i++)
		var2.c[i] = varp->c[i];
	printf("var2:[%d]\n", var2.a);
	printf("var2:[%d]\n", var2.c[1]);
	return 0;
}

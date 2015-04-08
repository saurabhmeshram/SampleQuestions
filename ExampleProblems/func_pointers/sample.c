#include<stdio.h>
int main(void)
{
	unsigned char c;
	unsigned int a;
	scanf("%d", &c);
	print_bits(c);
	printf("Val of a[%d]\n", (unsigned char) c);
	print_bits(c);
	return 0;
}

void print_bits(unsigned char x)
{
    int i;    
    for(i=7; i>=0; i--)
    {
	((x>>i) & 01) ? printf("1") : printf("0");
    }
    printf("\n");
}

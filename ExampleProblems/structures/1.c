/*
Demonstrates Size of Structure.

Refernces : http://en.wikipedia.org/wiki/Data_structure_alignment#Data_structure_padding
Throughly read about data alignment first.

Word Size for a 32Bit system is 4.
*/
# include <stdio.h>
int main(void)
{
#ifdef Q1
{	struct a 
	{
		char c;
		double d;
		int s;
	} a_t;
	printf("Size of Structure : [%d]\n", sizeof(a_t));
}
#endif

#ifdef Q2
{
	struct a
	{
		char x;
		char y[6];
	} a_t;
	printf("Size of Structure : [%d]\n", sizeof(a_t));
}
#endif

#ifdef Q3
{
	struct a
	{
		char c;
		int i;
		double d;
		char c1; 
	}a_t;

	struct b
	{
		struct a a_t; 
		char c;
		int i;
	}b_t;
	printf("Size of Structure a: [%d]\n", sizeof(a_t));
	printf("Size of Structure b: [%d]\n", sizeof(b_t));

}
#endif
	return 0;
}

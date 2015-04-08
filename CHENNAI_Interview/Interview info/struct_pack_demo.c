#include <stdio.h>

#pragma pack(1)
struct pack1_demo{
	int a;
	char b;
};
#pragma unpack

#pragma pack(2)
struct pack2_demo{
	int a;
	char b;
};
#pragma unpack

#pragma pack(4)
struct pack4_demo{
	int a;
	char b;
};
#pragma unpack

struct default_pack{ 
	int a;
	char b;
};

#pragma pack(6)
struct pack6_demo{
	int a;
	char b;
};
#pragma unpack

int main()
{
	printf("Declaration of Structure\n\nstruct <tag>{\n\tint a;\n\tchar b\n};\n\n"
		"\n\nSize of pack1 is %d\nSize of pack2 is %d\nSize of default pack is %d"
		"\nSize of pack4 is %d\nSize of pack 6 is %d\n",sizeof(struct pack1_demo),
	       	sizeof(struct pack2_demo),sizeof(struct default_pack), 
		sizeof(struct pack4_demo), sizeof(struct pack6_demo));
	return 0;
};




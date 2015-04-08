#include <stdio.h>
int main()
{
    int i = 0, line = 3;
    char ch[100] = {0};

    FILE *myfile;
    myfile = fopen("test.txt","r");
    if (myfile== NULL)
    {
	printf("can not open file \n");
	return 1;
    }

    while(line--){
	fscanf(myfile,"%s", ch);
	i++;
	printf("%s\n", &ch[i]);
    }

    fclose(myfile);
    return 0;
}

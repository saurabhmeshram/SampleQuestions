#include <stdio.h>

typedef struct myStruct {
    unsigned int myVar:1;
} myStruct; // my compiler requires TWO declarations of the name for typedef

int main()
{
myStruct myNewStructVar;
myNewStructVar.myVar = 0; // throws error that "myNewStructVar
return 0;
}

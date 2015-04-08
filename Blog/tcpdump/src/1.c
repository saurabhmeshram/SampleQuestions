#include "head.h"
int main()
{
    /**********************************************************************************************************************************/
    int nbytes = 255;
    char *encryptString;
    encryptString = (char *) malloc (nbytes + 1);
    //char encryptString[256];
    char finalChar;
    char finalString[256];
    int rotNum;
    /**********************************************************************************************************************************/    
    puts("Please enter the ROT (rotate) number you wish to encrypt by: ");
    scanf("%d", &rotNum);

    printf("Please enter the phrase you'd like to encrypt: \n");
    __fpurge(stdin);
    fgets(encryptString, sizeof(encryptString), stdin);
    encryptString[strlen(encryptString) - 1] = '\0';

    printf("The string entered is: %s\n", encryptString);
    printf("The encrypted version is: ");

    int n = strlen(encryptString) - 1;

    int i;
    for(i = 0; i < n; i++){     //For loop to go through the entire string entered
	if(isupper(encryptString[i])){
	    finalChar = (((encryptString[i] - 65) + rotNum) % 26) + 65;
	    finalString[i] = toupper(finalChar);
	    //printf("%c\n", finalChar);
	}

	else if(islower(encryptString[i])){
	    finalChar = (((encryptString[i] - 97) + rotNum) % 26) + 97;
	    finalString[i] = tolower(finalChar);
	    //printf("%c\n", finalChar);
	}

	else{
	    finalChar = ' ';
	    finalString[i] = finalChar;
	}

	printf("%c", finalString[i]);
    }
    printf("\n");
    return 0;
}

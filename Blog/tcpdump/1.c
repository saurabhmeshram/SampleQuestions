#include <stdio.h>

typedef int matrices[1000][1000];

void matrixGenerator(matrices *matrix, int rows, int columns) { 
    int genMatrix[rows][columns];
    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= columns; j++) {
            genMatrix[i][j] = 100; //Replace with some random value, 100 for testing
        }
    }
    matrix = &genMatrix;
}

int main(int argc, char *argv[]) 
{
    matrices *mainMatrix, *kernelMatrix;
    int rowsA = 0, columnsA = 0;
    int rowsB = 0, columnsB = 0;
    fprintf(stdout, "Enter number of rows and columns in the main matrix:");
    fscanf(stdin, "%d %d", &rowsA, &columnsA);
    matrixGenerator(mainMatrix, rowsA, columnsA);
    fprintf(stdout, "Enter number of rows and columns in the kernel matrix:");
    fscanf(stdin, "%d %d", &rowsB, &columnsB)   ;
    matrixGenerator(kernelMatrix, rowsB, columnsB);

    fprintf(stdout, "%d %d %d %d\n", rowsA, columnsA, rowsB, columnsB);

    for (int i = 0; i <= rowsA; i++) {
        for (int j = 0; j <= columnsA; j++) {
            fprintf(stdout, "%d\t", (*mainMatrix)[i][j]);
        }
        fprintf(stdout, "\n");
    }
    return 0;
}

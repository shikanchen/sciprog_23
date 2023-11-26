#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
#include "magic_square.h"

int getlines(char filename[MAX_FILE_NAME]);

int main(){  

    //define our file variable
    FILE *f;  
    char filename[MAX_FILE_NAME];
    printf("Enter file name: ");
    scanf("%s", filename);
    
    // ##! n function which gets the number of lines
    int n = getlines(filename);

    // Open the file 
    f = fopen(filename, "r");
    if (f == NULL) {
        perror("Error opening file");
        return 1;
    }


    int i;
    // Allocating a matrix for storing the magic square
    // as an array of pointers, where each pointer is a row 
    int **square = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        square[i] = (int *)malloc(n * sizeof(int));
    }

    // inputting integer data into the matrix;
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(f, "%d", &square[i][j]);
        }
    }

    // call isMagicSaure defined in magic_square.h to check
    // if the square is magic
    if (isMagicSquare(square, n)) {
        printf("The square is magic.\n");
    } else {
        printf("The square is not magic.\n");
    }

    // Freeing each row separately before freeing the array of pointers
    for (i = 0; i < n; i++) {
        free(square[i]);
    }
    free(square);

    // Close the file
    fclose(f);


    return 0;
}  

//##!

int getlines(char filename[MAX_FILE_NAME]) {
    FILE *fp;
    fp = fopen(filename, "r");
    
    int ch_read;
    int count = 0;

    while( (ch_read = fgetc(fp)) != EOF)
    {
        if (ch_read == '\n'){
            count++;
        }
    }

    printf("No. lines, %d\n", count);
    fclose(fp); 
    return count;
}

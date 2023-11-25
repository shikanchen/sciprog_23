#include <stdio.h>
#include <stdlib.h>

int *allocatearray(int size) {
    // allocate memory for array
    return (int *)malloc(size * sizeof(int));
}

void fillwithones(int *array, int size) {
    // init with ones
    for (int i = 0; i < size; ++i) {
        array[i] = 1;
    }
}

void printarray(int *array, int size) {
    // print the array
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void free_memory(int *array) {
    // free the allocated memory
    free(array);
}

int main() {

    // size settings for testing
    int sizes[] = {5, 10, 15};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    // loop through all sizes of the setting
    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        printf("\nCreating an array of size %d\n", size);

        int *array = allocatearray(size);
        printf("Filling array with ones\n");
        fillwithones(array, size);

        printf("Printing array:\n");
        printarray(array, size);

        printf("Freeing allocated memory\n");
        free_memory(array);
        printf("Memory freed\n");
    }

    return 0;
}

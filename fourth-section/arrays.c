#include <stdlib.h>
#include <stdio.h>

void StackArray(int multiplier) {
    int length = multiplier * 4096;
    printf("Will create and initialize array with length %d on the stack\n", length);
    int someArray[length] = {};
    for (int i = 0; i < length; i++) {
        someArray[i] = i;
    }
    printf("Done\n");
}

void HeapArray(int multiplier) {
    int length = multiplier * 4096;
    printf("Will create and initialize array with length %d on the heap\n", length);
    int* someArray = (int *) malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        someArray[i] = i;
    }
    free(someArray);
    printf("Done\n");
}

int main(int argc, char* argv[]) {
    int multiplier = 0;
    while (scanf("%d", &multiplier)) {
        if (argc == 1) {
            // crashes for any value >= 512
            StackArray(multiplier);
        } else {
            HeapArray(multiplier);
        }
    }
}
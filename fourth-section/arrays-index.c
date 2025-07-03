#include <stdlib.h>
#include <stdio.h>

void StackArray(int multiplier) {
    int length = multiplier * 4096;
    printf("Will create and initialize array with length %d on the stack\n", length);
    int someArray[length] = {};
    for (int i = 0; i < 2 * length; i++) {
        someArray[i] = i;
    }
    printf("Done\n");
}

void StackArrayAddresses(int multiplier) {
    int length = multiplier * 4096;
    printf("Will create and initialize array with length %d on the stack, length at %p\n", length, &length);
    int someArray[length] = {};
    printf("Array starts at %p\n", someArray);
    for (int i = 0; i < 2 * length; i++) {
        someArray[i] = i;
    }
    printf("Done\n");
}

int main(int argc, char* argv[]) {
    int multiplier = 0;
    while (scanf("%d", &multiplier)) {
        if (argc == 1) {
            StackArray(multiplier);
        } else {
            StackArrayAddresses(multiplier);
        }
    }
}
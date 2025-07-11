#include <stdlib.h>
#include <stdio.h>

void AsPtr(int* array) {
    printf("Address of array: %p\n", array);
    array[1] = 42;
}

void AsArray(int array[]) {
    printf("Address of array: %p\n", array);
    array[2] = 17;
}

void printSize(int arraySize) {
    printf("Will initialize array with size %d\n", arraySize);
    int someArray[arraySize] = {};
    printf("Address of array: %p\n", someArray);
    AsPtr(someArray);
    AsArray(someArray);
    printf("Elements: 1: %d - 2: %d\n", someArray[1], someArray[2]);
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        return 0;
    }
    
    int size = atoi(argv[1]);
    printSize(size);
}
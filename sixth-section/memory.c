#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


typedef enum {
    FREE_CRASH = 1,
    MALLOC_CALLOC_SIZE = 2,
    MALLOC_CALLOC_BREAK = 3,
} action;


void FreeWrapper(void* somePtr) {
    free(somePtr);
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        return 0;
    }

    action selectedAction = atoi(argv[1]);

    switch (selectedAction) {
        case FREE_CRASH: {
            printf("Chose FREE_CRASH action\n");
            int* someArray = (int*) malloc(8 * sizeof(int));
            FreeWrapper((void *) (someArray + 4));

            // unreachable
            break;
        }
        case MALLOC_CALLOC_SIZE: {
            printf("Chose MALLOC_CALLOC_SIZE action\n");
            char *someArray = (char *) malloc(8589934592 / 2);
            assert(someArray);
            printf("All good? %c, about to calloc\n", someArray ? 'y' : 'n');
            free(someArray);
            char *someOtherArray = (char *) calloc(8589934592 / 2, sizeof(char));
            assert(someOtherArray);
            // char *someOtherArray = calloc(85899, sizeof(char));
            
            printf("calloc worked? %c\n", someOtherArray ? 'y' : 'n');
            break;
        }
        case MALLOC_CALLOC_BREAK: {
            printf("Chose MALLOC_CALLOC_SIZE action\n");
            char *someArray = (char *) malloc(8589934592 / 2);
            assert(someArray);

            // char *someArray = (char *) malloc(85899 * sizeof(char));
            printf("All good? %c, about to access", someArray ? 'y' : 'n');
            for (int i = 0; i < 8589934592 / 2; i++) {
                someArray[i] = 42;
            }
            free(someArray);
            printf("about to calloc\n");
            char *someOtherArray = (char *) calloc(8589934592 / 2, sizeof(char));
            assert(someOtherArray);
            for (int i = 0; i < 8589934592 / 2; i++) {
                someOtherArray[i] = 42;
            }
            // char *someOtherArray = calloc(85899, sizeof(char));
            
            printf("calloc worked? %c\n", someOtherArray ? 'y' : 'n');
            break;
        }
    }
    
}
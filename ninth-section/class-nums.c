#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child = fork();
    
    if (child < 0) {
        perror("fork failed");
        return 1;
    } else if (child > 0) {
        printf("PARENT\n");
        for (int i = 0; i <= 10; i++) {
            if (i % 2 == 0) {
                printf("%d ", i);
            }
        }

        printf("\n");
    } else {
        printf("CHILD\n");
        for (int i = 0; i <= 10; i++) {
            if (i % 2) {
                printf("%d ", i);
            }
        }

        printf("\n");
    }
}
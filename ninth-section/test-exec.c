#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child = fork();

    if (child < 0) {
        perror("fork failed");
        return 1;
    }

    if (!child) {
        char** args = (char**) malloc(3 * sizeof(char*));
        args[0] = "touch";
        args[1] = "/tmp/test";
        args[2] = (char *) 0;
        if (execv("/bin/touch", args)) {
            perror("exec failed");
            return 1;
        }

        return 0;
    }

    int* cStatus = NULL;
    if (wait(cStatus) < 0) {
        perror("wait failed");
        return 1;
    }
    return 0;
}
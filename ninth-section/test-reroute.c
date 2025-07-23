#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main() {
    int target_file = open(
        // Path to file
        "/tmp/test_file",
        // Flags -- here we're saying we want the file to be created if it does
        // not exist, and that we're trying to open it both for reading and writing.
        O_CREAT | O_RDWR,
        // File mode bits to set -- see
        // https://www.gnu.org/software/coreutils/manual/html_node/Mode-Structure.html
        // for more. Here we're saying that the current user should have read and write
        // permissions to the file being created.
        S_IRUSR | S_IWUSR,
    );

    if (target_file < 0) {
        perror("open failed");
        return 1;
    }

    int new_stdout = dup(1);
    if (new_stdout < 0) {
        perror("dup failed");
        return 1;
    }
    if (close(1) < 0) {
        perror("stdout close failed");
        return 1;
    }

    if (dup2(target_file, 1) < 1) {
        perror("dup of output fd to stdout fd failed");
        return 1;
    }

    pid_t child = fork();

    if (child < 0) {
        perror("fork failed");
        return 1;
    }

    if (!child) {
        char** args = (char**) malloc(3 * sizeof(char*));
        args[0] = "echo";
        args[1] = "Echoed String";
        args[2] = (char *) 0;
        if (execv("/bin/echo", args)) {
            perror("exec failed");
            return 1;
        }

        return 0;
    }

    if (close(1) < 0) {
        perror("output file close failed");
        return 1;
    }
    
    if (dup2(new_stdout, 1) < 0) {
        perror("resetting of stdout fd failed");
        return 1;
    }

    int* cStatus = NULL;
    if (wait(cStatus) < 0) {
        perror("wait failed");
        return 1;
    }
    printf("All done\n");
    return 0;
}
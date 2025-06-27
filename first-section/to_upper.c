#include <stdio.h>

int main(int argc, char* argv[]) {
    char input;
    while (1) {
        int ret = scanf("%c", &input);
        if (ret == EOF) {
            printf("EOF reached, stopping\n");
            break;
        }
        
        if (input < 97 || input > 122) {
            printf("%c", input);
            continue;
        }
        printf("%c", input - 32);
    }

    return 0;
}
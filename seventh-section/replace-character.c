// Try running this with the sample file as
// $ cc replace-character.c -o replace
// $ replace sample-text a b

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Invalid number of args: expected 3 got %d\n", argc - 1);
        exit(1);
    }

    // Parse arguments
    char* filePath = argv[1];
    FILE* targetFile = fopen(filePath, "r+");
    if (!targetFile) {
        char* errorMsg = (char *) calloc(strlen(filePath) + 50, sizeof(char));
        sprintf(errorMsg, "Failed to open file '%s'", filePath);
        perror(errorMsg);
        exit(1);
    }

    char sourceChar = argv[2][0];
    if (!isalpha(sourceChar)) {
        fprintf(stderr, "Source char '%c' needs to be one of a-z, A-Z\n", sourceChar);
        exit(1);
    }

    char targetChar = argv[3][0];
    if (!isalpha(targetChar)) {
        fprintf(stderr, "Target char '%c' needs to be one of a-z, A-Z\n", targetChar);
        exit(1);
    }

    // Processing loop
    char readCharacter;
    while ((readCharacter = fgetc(targetFile)) != EOF) {
        if (readCharacter != sourceChar) {
            // nothing to do, skip
            continue;
        }

        fseek(targetFile, -1, SEEK_CUR);
        fputc(targetChar, targetFile);
    }

    // Check if we actually hit EOF or if another error occured in fgetc()
    if (!feof(targetFile)) {
        char* errorMsg = (char *) calloc(strlen(filePath) + 50, sizeof(char));
        sprintf(errorMsg, "Error encountered while processing '%s'", filePath);
        perror(errorMsg);
        exit(1);
    }

    return 0;
}
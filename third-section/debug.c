#include <stdio.h>

int WillRaiseArithmeticException(int n) {
    // incorrect base condition
    if (n < 0) {
        return 42;
    }

    return WillRaiseArithmeticException(n - 1) / n;
}

int WillEncounterStackOverflow(int n) {
    if (n <= 0) {
        return 42;
    }

    return WillEncounterStackOverflow(n) / n;
}

int main(int argc, char* argv[]) {
    int userInput = 0;
    printf("Base number: ");
    scanf("%d", &userInput);
    printf("%d\n", WillRaiseArithmeticException(userInput));
    return 0;
}
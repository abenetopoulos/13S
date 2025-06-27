
#include <stdio.h>

int main() {
    int num = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    int reverse = 0;

    while (num != 0) {
        int digit = num % 10;
        reverse = reverse * 10 + digit;
        num /= 10;
    }

    printf("Reversed number: %d\n", reverse);

    return 0;
}
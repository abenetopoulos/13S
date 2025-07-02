#include <stdio.h>

unsigned int UIntAdd();

int main(void) {
    int x = 5;
    printf("%u\n", UIntAdd(++x, ++x));
    return 0;
}

unsigned int UIntAdd(unsigned int n, unsigned int p) {
    printf("%u, %u\n", n, p);
    return n + p;
}
#include <stdlib.h>
#include <stdio.h>

typedef struct my_struct {
    int a_member;
} my_struct;

void SomeFunc() {
    my_struct foo;
    printf("func value: %d\n", foo.a_member);
}

int main() {
    my_struct foo;
    printf("value: %d\n", foo.a_member);
    // SomeFunc();
}
#include <stdio.h>

typedef enum some_enum_t {
    SE_FIRST, // 0
    SE_SECOND = -1,
    SE_COUNT, // also 0
} some_enum;

int main() {
    printf("%d\n", SE_FIRST == SE_COUNT);
}
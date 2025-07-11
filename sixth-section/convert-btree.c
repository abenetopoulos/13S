#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node_t {
    int key;
    struct node_t *left;
    struct node_t *right;
} node;

typedef struct conversion_helper_t {
    int* arr;
    unsigned int numValidElements;
    unsigned int currentLength;
} conversion_helper;

conversion_helper Convert(node* root, conversion_helper helper, unsigned int rootIdx) {
    if (root == NULL) {
        return helper;
    }

    if (rootIdx > helper.currentLength) {
        unsigned int currentLength = helper.currentLength;
        unsigned int multiplier = ceil(1.0 * rootIdx / (double) helper.currentLength);

        helper.currentLength *= multiplier;
        helper.arr = realloc((void *) helper.arr, multiplier * currentLength * sizeof(int));
        for (int i = currentLength; i < helper.currentLength; i++) {
            helper.arr[i] = 0;
        }
    }

    helper.arr[rootIdx] = root->key;
    helper.numValidElements++;

    helper = Convert(root->left, helper, 2 * rootIdx);
    helper = Convert(root->right, helper, 2 * rootIdx + 1);

    return helper;
}

int main(void) {
    // sample data
    node root = { .key = 42, .left = NULL, .right = NULL};
    node left = { .key = 11, .left = NULL, .right = NULL};
    root.left = &left;
    node right = { .key = 52, .left = NULL, .right = NULL};
    // try assigning `right` as a child of `left` to see how the program's output changes.
    root.right = &right;

    int* targetArray = (int *) calloc(2, sizeof(int));
    conversion_helper helper = { .arr = targetArray, .numValidElements = 0, .currentLength = 2};

    helper = Convert(&root, helper, 1);

    for (int i = 1; i < helper.currentLength; i++) {
        printf("%d ", helper.arr[i]);
    }
    printf("\n");
}
#include <stdlib.h>
#include <stdio.h>

typedef struct node_t {
    int key;
    struct node_t *next;
} node;

void PrintReverse(node* startNode) {
    if (startNode == NULL) {
        return;
    }

    printf("%d ", startNode->key);
    PrintReverse(startNode->next);
}

int main(void) {
    node headNode = { .key = 42, .next = NULL};
    node secondNode = { .key = 52, .next = NULL };

    headNode.next = &secondNode;

    PrintReverse(&headNode);
    printf("\n");
}
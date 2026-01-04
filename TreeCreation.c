#include <stdio.h>

#define SIZE 15

char nodes[SIZE];

void initTree() {
    int i;
    for (i = 0; i < SIZE; i++)
        nodes[i] = '-';
}

void addRoot(char val) {
    nodes[0] = val;
}

void addLeftChild(char val, int parent) {
    int pos = parent * 2 + 1;
    if (parent >= SIZE || pos >= SIZE || nodes[parent] == '-')
        return;
    nodes[pos] = val;
}

void addRightChild(char val, int parent) {
    int pos = parent * 2 + 2;
    if (parent >= SIZE || pos >= SIZE || nodes[parent] == '-')
        return;
    nodes[pos] = val;
}

void displayTree() {
    int i;
    for (i = 0; i < SIZE; i++)
        printf("%c ", nodes[i]);
    printf("\n");
}

int main() {
    initTree();

    addRoot('A');
    addLeftChild('B', 0);
    addRightChild('C', 0);
    addLeftChild('D', 1);
    addRightChild('E', 1);
    addRightChild('F', 2);

    displayTree();

    return 0;
}

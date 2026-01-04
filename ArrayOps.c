#include <stdio.h>

void showArray(const int data[], int length) {
    int i = 0;
    while (i < length) {
        printf("%d ", data[i]);
        i++;
    }
    printf("\n");
}

void addAtIndex(int data[], int *length, int index, int value) {
    int i;
    for (i = *length - 1; i >= index; i--) {
        data[i + 1] = data[i];
    }
    data[index] = value;
    (*length)++;
}

void removeAtIndex(int data[], int *length, int index) {
    int i = index;
    while (i < *length - 1) {
        data[i] = data[i + 1];
        i++;
    }
    (*length)--;
}

int main() {
    int data[100] = {10, 20, 30, 40, 50};
    int length = 5;

    printf("Initial Array: ");
    showArray(data, length);

    addAtIndex(data, &length, 2, 25);
    printf("After Insert:  ");
    showArray(data, length);

    removeAtIndex(data, &length, 3);
    printf("After Delete:  ");
    showArray(data, length);

    return 0;
}

#include <stdio.h>

/*
 * MAX HEAP  -> Parent >= Children
 * MIN HEAP  -> Parent <= Children
 */

#define MAX 50

/* ---------- ORTAK ---------- */
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

/* ---------- MAX HEAP ---------- */
void maxHeapify(int arr[], int n, int i){
    int largest = i;
    int left  = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

/* ---------- MIN HEAP ---------- */
void minHeapify(int arr[], int n, int i){
    int smallest = i;
    int left  = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest])
        smallest = left;

    if(right < n && arr[right] < arr[smallest])
        smallest = right;

    if(smallest != i){
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

/* ---------- YAZDIR ---------- */
void printArray(int arr[], int n){
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* ---------- MAIN ---------- */
int main(){
    int data[] = {4, 10, 3, 5, 1};
    int n = sizeof(data)/sizeof(data[0]);

    int maxHeap[MAX], minHeap[MAX];

    for(int i=0;i<n;i++){
        maxHeap[i] = data[i];
        minHeap[i] = data[i];
    }

    buildMaxHeap(maxHeap, n);
    printf("Max Heap: ");
    printArray(maxHeap, n);

    buildMinHeap(minHeap, n);
    printf("Min Heap: ");
    printArray(minHeap, n);

    return 0;
}

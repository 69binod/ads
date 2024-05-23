#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *heap;
    int size;
    int capacity;
} MaxHeap;

void initMaxHeap(MaxHeap *h, int capacity)
{
    h->heap = (int *)malloc(capacity * sizeof(int));
    h->size = 0;
    h->capacity = capacity;
}

void heapifyUp(MaxHeap *h, int index)
{
    int parentIndex = (index - 1) / 2;
    if (index > 0 && h->heap[parentIndex] < h->heap[index])
    {
        int temp = h->heap[parentIndex];
        h->heap[parentIndex] = h->heap[index];
        h->heap[index] = temp;
        heapifyUp(h, parentIndex);
    }
}

void insert(MaxHeap *h, int element)
{
    if (h->size == h->capacity)
    {
        printf("Max-Heap is full\n");
        return;
    }
    h->heap[h->size] = element;
    heapifyUp(h, h->size);
    h->size++;
}

void display(MaxHeap *h)
{
    for (int i = 0; i < h->size; ++i)
    {
        printf("%d ", h->heap[i]);
    }
    printf("\n");
}

void freeMaxHeap(MaxHeap *h)
{
    free(h->heap);
}

int main()
{
    MaxHeap maxHeap;
    int capacity = 100; // Arbitrary capacity for the heap
    initMaxHeap(&maxHeap, capacity);

    int choice, element;
    while (1)
    {
        printf("1. Insert element into Max-Heap\n");
        printf("2. Display Max-Heap\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &element);
            insert(&maxHeap, element);
            break;
        case 2:
            printf("Max-Heap elements: ");
            display(&maxHeap);
            break;
        case 3:
            freeMaxHeap(&maxHeap);
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

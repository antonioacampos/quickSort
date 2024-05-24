#include "stack.h"
#include "quickSort.h"
#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Função para implementar o Quick Sort iterativo
void quickSortIterative(int arr[], int l, int h) {
    Stack *stack = create_stack(h - l + 1);
    push(stack, l);
    push(stack, h);

    while (!is_empty(stack)) {
        pop(stack, &h);
        pop(stack, &l);

        int p = partition(arr, l, h);

        if (p - 1 > l) {
            push(stack, l);
            push(stack, p - 1);
        }

        if (p + 1 < h) {
            push(stack, p + 1);
            push(stack, h);
        }
    }

    destroy_stack(stack);
}

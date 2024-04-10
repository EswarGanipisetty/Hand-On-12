#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} DynamicArray;

void initDynamicArray(DynamicArray* arr, size_t initialCapacity) {
    arr->data = (int*)malloc(initialCapacity * sizeof(int));
    arr->size = 0;
    arr->capacity = initialCapacity;
}

void freeDynamicArray(DynamicArray* arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

void resizeDynamicArray(DynamicArray* arr, size_t newCapacity) {
    arr->data = (int*)realloc(arr->data, newCapacity * sizeof(int));
    if (arr->data == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
    arr->capacity = newCapacity;
}

void pushBack(DynamicArray* arr, int value) {
    if (arr->size >= arr->capacity) {
        size_t newCapacity = arr->capacity == 0 ? 1 : arr->capacity * 2;
        resizeDynamicArray(arr, newCapacity);
    }
    arr->data[arr->size++] = value;
}

int main() {
    DynamicArray arr;
    initDynamicArray(&arr, 2); // initial capacity of 2

    // Push some elements into the dynamic array
    pushBack(&arr, 10);
    pushBack(&arr, 20);
    pushBack(&arr, 30);
    pushBack(&arr, 40);

    // Print the elements
    printf("Dynamic array elements: ");
    for (size_t i = 0; i < arr.size; ++i) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");

    // Free memory
    freeDynamicArray(&arr);

    return 0;
}

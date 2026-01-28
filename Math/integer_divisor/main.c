#include <stdio.h>
#include <stdlib.h>


void add_to_array(int **array, int *size, int value);

int* divisors_of(int a, int *size) {
    int *array = NULL;
    *size = 0;

    while (a != 0) {
        a /= 2;
        add_to_array(&array, size, a);
    }

    return array;
}

// Add new element to dynamic array
void add_to_array(int **array, int *size, int value) {
    int *temp = realloc(*array, (*size + 1) * sizeof(int));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    *array = temp;
    (*array)[*size] = value;
    (*size)++;
}

int main() {
    int size;
    int *result = divisors_of(100, &size);

    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }

    free(result);
    return 0;
}

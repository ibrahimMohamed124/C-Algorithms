#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    // Sort the array
    qsort(arr, arrSize, sizeof(int), cmp);

    // Expected common difference
    int diff = arr[1] - arr[0];

    // Check if all differences match
    for (int i = 1; i < arrSize - 1; i++) {
        if (arr[i + 1] - arr[i] != diff)
            return false;
    }

    return true;
}

int main() {
    int arr1[] = {3, 5, 1};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Result 1: %d\n", canMakeArithmeticProgression(arr1, len1));

    int arr2[] = {1, 2, 4};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Result 2: %d\n", canMakeArithmeticProgression(arr2, len2));

    return 0;
}

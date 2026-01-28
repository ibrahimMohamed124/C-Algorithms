#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool canMakeGeometricSequence(int* arr, int arrSize){

    if (arrSize < 2) return true;

    qsort(arr, arrSize, sizeof(int), cmp);

    // Check Geometric Sequence Validation
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == 0) return false;
    }

    double ratio = (double)arr[1] / arr[0];

    for (int i = 0; i < arrSize - 1; i++) {
        if ((double)arr[i+1] / arr[i] != ratio) {
            return false;
        }
    }

    return true;
}

int main() {
    int arr[] = {2, 8, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (canMakeGeometricSequence(arr, size))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

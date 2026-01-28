#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int arr[], int len)
{
    int* res = (int*)malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        int prod = 1;
        for (int j = 0; j < len; j++) {
            if (i != j)
                prod *= arr[j];
        }
        res[i] = prod;
    }

    return res;
}

int main()
{
    int arr[] = {1, 2, 4, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    int* result = productExceptSelf(arr, len);

    for (int i = 0; i < len; i++)
        printf("%d ", result[i]);

    free(result);
    return 0;
}

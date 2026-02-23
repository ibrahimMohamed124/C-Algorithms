#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long long *parts_sums(size_t *len,
                               const unsigned long long ls[],
                               size_t n)
{
    *len = n + 1;

    unsigned long long *sum_parts =
        malloc((*len) * sizeof(unsigned long long));

    if (!sum_parts) return NULL;

    unsigned long long sum = 0;

    // calculate total sum
    for (size_t i = 0; i < n; i++) {
        sum += ls[i];
    }

    // fill suffix sums
    for (size_t i = 0; i < n; i++) {
        sum_parts[i] = sum;
        sum -= ls[i];
    }

    sum_parts[n] = 0;

    return sum_parts;
}

int main()
{
    unsigned long long arr[] = {0, 1, 3, 6, 10};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    size_t result_len;

    unsigned long long *result = parts_sums(&result_len, arr, n);

    if (!result) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Suffix sums:\n");
    for (size_t i = 0; i < result_len; i++) {
        printf("%llu ", result[i]);
    }

    printf("\n");

    free(result);
    return 0;
}

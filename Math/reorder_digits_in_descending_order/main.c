#include <inttypes.h>
#include <string.h>
#include <stdio.h>

uint64_t descendingOrder(uint64_t n)
{
    char strn[32];

    // Correct format for uint64_t
    sprintf(strn, "%" PRIu64, n);

    int len = strlen(strn);

    // Bubble sort (descending)
    for(int i = 0; i < len - 1; i++) {
        for(int j = 0; j < len - 1 - i; j++) {
            if(strn[j] < strn[j + 1]) {
                char temp = strn[j];
                strn[j] = strn[j + 1];
                strn[j + 1] = temp;
            }
        }
    }

    // Convert back to uint64_t
    uint64_t sorted_num = 0;
    for(int i = 0; i < len; i++) {
        sorted_num = sorted_num * 10 + (strn[i] - '0');
    }

    return sorted_num;
}

int main() {
    uint64_t n,res;

    printf("Enter a number: ");
    scanf("%" SCNu64, &n);   // correct input format for uint64_t

    res = descendingOrder(n);

    printf("Sorted (descending): %" PRIu64 "\n", res);
    return 0;
}

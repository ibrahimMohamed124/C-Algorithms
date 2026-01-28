#include <stdio.h>

#define LENGTH(array) (sizeof(array) / sizeof(array[0]))

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to segregate negative and positive numbers
void segregate_neg_pos(int array[], int size) {
    int i = 0, j = size - 1;

    while(i < j){
        while(array[i] < 0 && i < j) i++;     // skip negatives
        while(array[j] >= 0 && i < j) j--;    // skip positives
        if(i < j) swap(&array[i], &array[j]);
    }
}

void print_array(int array[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {1, -10, 50, 40, -71, 20, 90, 100};
    int size = LENGTH(array);

    printf("Original array: ");
    print_array(array, size);

    segregate_neg_pos(array, size);

    printf("Segregated array: ");
    print_array(array, size);

    return 0;
}

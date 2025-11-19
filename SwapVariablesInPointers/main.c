#include <stdio.h>
#include <stdlib.h>


void swap(int* ptr1, int* ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int num1 = 7;
    int num2 = 5;

    printf("Before Swapping: num1 = %d, num2 = %d\n", num1, num2);

    swap(&num1, &num2);

    printf("After Swapping: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}

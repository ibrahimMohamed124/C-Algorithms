#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int number, original, rem, sum = 0, digit = 0;

    printf("Enter Number: ");
    scanf("%d", &number);

    original = number;

    // count number of digits
    while (number != 0) {
        digit++;
        number /= 10;
    }
    
    number = original;

    while (number != 0) {
        rem = number % 10;
        sum += pow(rem, digit);
        number /= 10;
    }

    if (sum == original) {
        printf("%d is Armstrong Number\n", original);
    } else {
        printf("%d is not an Armstrong Number\n", original);
    }

    return 0;
}

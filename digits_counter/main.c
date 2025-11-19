#include <stdio.h>
#include <stdlib.h>

int count_digits(int a);

int main()
{
    int digits_num = count_digits(7798);
    printf("%d\n", digits_num);
    return 0;
}

int count_digits(int a){
    int count = 0;
    while(a){
        a/=10;
        count++;
    }
    return count;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    start:
    int n,r;
    printf("Enter a Number to Reverse: ");
    scanf("%d", &n);

    while(n){
        r = n * 10 + n%10;
        n/=10;
    }
    goto start;
    return 0;
}

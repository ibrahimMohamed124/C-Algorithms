#include <stdio.h>
#include <stdlib.h>

int recursive_factorial(int a);

int main()
{
    int fact = 7;
    printf("%d\n", recursive_factorial(fact));

    return 0;
}

int recursive_factorial(int a){
    if(a <=1) return 1;
    return a*recursive_factorial(a - 1);
}

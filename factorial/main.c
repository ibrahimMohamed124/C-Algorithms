#include <stdio.h>
#include <stdlib.h>

int factorial(int a);

int main()
{
    unsigned long long res = factorial(10);
    printf("%d", res);
    return 0;
}

int factorial(int a){
    unsigned long long res =1;
    for(int i =1;i<=a;i++){
        res*=i;
    }
    return res;
}

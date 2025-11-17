#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define binary_search(arr, target) binary_search_internal(arr, sizeof(arr)/sizeof(arr[0]), target)

int binary_search_internal(int array[], int length, int target);

int main()
{
    int array[] = {1,2,3,4,5};
    int target = 5;

    int res = binary_search(array, target);

    if(res == -1) printf("%d Not Found",target);
    else printf("%d Found at %d",target,res);

    return 0;
}

int binary_search_internal(int array[], int length, int target){
    if(length <= 1) return -1;

    int mid = floor(length / 2);

    for(int i = 0; i < length; i++){
        if(target == array[mid]) return mid;

        if(target > array[mid]) mid++;
        else mid--;

        if(mid < 0 || mid >= length)
            return -1;
    }

    return -1;
}

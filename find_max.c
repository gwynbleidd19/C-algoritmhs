#include <stdio.h>

int find_max(int *arr, int len){
    int *ptr = arr;
    int max = *ptr;
    int i = 1;
    while (i != len){
        ptr++;
        i++;
        if (max < *ptr) max = *ptr;
    }
    return max;
}



int main(void){
    int array[] = {3, 5, 2, 7};
    int len = sizeof(array) / sizeof(array[0]);
    int result = find_max(array, len);
    
    printf("%d", result);
}
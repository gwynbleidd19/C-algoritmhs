#include <stdio.h>
#include <stdint.h>

int mstrlen(const char *str){
    int result;
    while (*str){
        str++;
        result++;
    }
    return result;
}


int main(void){
   const char str[] = "Embedded";
   int res = mstrlen(str);
    printf("%d\r\n", res);
}
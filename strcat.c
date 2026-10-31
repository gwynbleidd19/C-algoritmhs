#include <stdio.h>

void mstrcat(char *dest, const char *str){
    char *ptr = dest;
    while (*ptr) {
        ptr++;
    }
    while (*str){
        *ptr = *str;
        ptr++;
        str++;
    }
    *ptr = '\0';
}



int main(void){

    char text[60] = "Hello";
    mstrcat(text, ", how are you?");
    
    printf("%s", text);


    return 0;
}
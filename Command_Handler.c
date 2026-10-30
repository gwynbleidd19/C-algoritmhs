#include <stdio.h>
#include <stdint.h>

int mstrcmp(const char *s1, const char *s2);
void cmd_help(int argc, char **argv);
void cmd_echo(int argc, char **argv);
void cmd_add(int argc, char **argv);

typedef struct {
    const char *name;
    void (*handler)(int argc, char **argv);
} command;

command commands[] = {
    {"help", cmd_help},
    {"echo", cmd_echo},
    {"add", cmd_add}
};

int tokenize(char *str, char **argv){
    int count = 0;
    while (*str != '\0'){
        if (*str == ' ' || *str == '\n'){ // <--- 1. Добавили \n (ИЛИ)
            str++;
        } else {
            argv[count] = str;
            count++;
        }
        
        // 2. Убрали лишнее, оставили проверку на пробел, \n и \0
        while (*str != ' ' && *str != '\n' && *str != '\0'){
            str++;
        }
        
        // 3. Исправили && на ||, добавили одинарные кавычки для \n
        if (*str == ' ' || *str == '\n'){ 
            *str = '\0';
            str++;
        }
    }
    return count;
}

int mstrcmp(const char *s1, const char *s2){
    while (*s1 && *s1 == *s2){
        s1++;
        s2++;
    }
    
    return (unsigned char)*s1 - (unsigned char)*s2;
}

int matoi(const char *str){
    int result = 0;
    while (*str != '\0'){
        if (*str >= '0' && *str <= '9'){
            result = result * 10 + (*str - '0');
            str++;
        } else str++;
    }
    return result;
}

void cmd_help(int argc, char **argv){
    (void)argc;
    (void)argv;
    printf("Available commands: help, echo, add");
}

void cmd_echo(int argc, char **argv){
    for (int i = 1; i < argc; i++){
        printf("%s\r\n", argv[i]);
    }
}

void cmd_add(int argc, char **argv){
    if (argc < 3) {
        printf("Wrong parameters, example: add 14 53");
        return;
    }
    int total = 0;
    for (int i = 1; i < argc; i++){
   int a = matoi(argv[i]);
   total = total + a;
  
}
 printf("%d", total);
}

void execute_commands(int argc, char **argv){
    int count = sizeof(commands) / sizeof(commands[0]);

    for (int i = 0; i < count; i++){
        if (mstrcmp(argv[0], commands[i].name) == 0){
            commands[i].handler(argc, argv);

                return;
        }
    }
    printf("Unknown command");
}

int main(void){
    char *argv[20];
    char str[100];
    
    printf("Enter command: ");
    scanf("%99[^\n]", str);
    int res = tokenize(str, argv); // result
    execute_commands(res, argv);


    

    return 0; 
}
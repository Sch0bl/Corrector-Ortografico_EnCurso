#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "utils.h"

int compara_string(char* str1, char* str2){
    int i = 0;
    while (str1[i]  != '\0' && str2[i]  != '\0'){
        if (str1[i] != str2[i])
           return 0;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
        return 1;
    return 0;
}
void destruye_string(char* str) {free(str);}

char* copia_string(char* str){
    char* str_copia;
    int i = 0, cantidad_inicial = 15;
    str_copia = malloc(sizeof(char)* 15);
    for (; str[i] != '\0'; i++){
        if (i == 14){
            cantidad_inicial *= 2;
            str_copia = realloc(str_copia, cantidad_inicial);
        }
        str_copia[i] = str[i];
    }
    return str_copia;
}

unsigned string_hashear(char* str){
    return KRHash(str);
}

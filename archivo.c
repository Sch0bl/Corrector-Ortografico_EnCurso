#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"
#define CANTIDAD_CHAR_INICIAL 10

char* toma_palabra(char* palabra, FILE* fp, int* c){
    int cant_char_variable = 2*CANTIDAD_CHAR_INICIAL;
   
    for(int i = 0; i < 10; i++){
        *c = fgetc(fp);
        if (*c != '\n'){
            palabra = realloc(palabra, cant_char_variable);
            cant_char_variable *= 2;
            palabra[i] = *c;
        }
        else
            i = CANTIDAD_CHAR_INICIAL;
    }
    return palabra;
}

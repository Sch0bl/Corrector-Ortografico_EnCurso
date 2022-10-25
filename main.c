#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"
#include "hash.h"
#include "glist.h"
#include "strings.h"

#define CANTIDAD_CHAR_INICIAL 10
#define CANTIDAD_TABLAHASH_INICIAL 10000

int main(){

    char* dict; //Acá se va a guardar el nombre del diccionario
                //Pasado a través de main. VER ESO.

    FILE* fp;
    fp = fopen("dicTest.txt", "r");
    char* palabra;
    int c = 0;
    
    TablaHash tabla = tablahash_crear(
        CANTIDAD_TABLAHASH_INICIAL, (FuncionCopiadora)copia_string,
        (FuncionComparadora)compara_string,
        (FuncionDestructora)destruye_string, (FuncionHash)string_hashear);
    //Pregunta: Le debería pasar la función de string o la de glist?
    
    palabra = malloc(sizeof(char) * CANTIDAD_CHAR_INICIAL);
    palabra = toma_palabra(palabra, fp, &c);
    while (c != EOF){
        tablahash_inserta_encadenamiento(tabla, palabra);
        palabra = toma_palabra(palabra, fp, &c);
    }

    return 0;
}
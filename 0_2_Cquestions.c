// C programming (important questions set 2)
// https://www.youtube.com/watch?v=hTUvEURkNeA

// Q1: What is the output of the following C program fragment?

#include<stdio.h>
int main(){
    int var = 052;// 058 (octal) = 5*8^1 + 2*8^0 (decimal) = 42 (decimal)
    printf("%d\n", var);
    printf("%o\n", var);
    return 0;
}

// Comentario: el literal 052 es octal. Si pero lo importante es con qué 
// formato lo imprimimos: como estamos usando %d, lo estamos imprimiendo en 
// formato decimal. Con el segundo printf sí que lo estamos imprimiendo en
// formato octal, así que si solo hubiéramos escrito este segundo printf
// el programa no tendía que hacer ninguna conversión.

// Q1: What is the output of the following C program fragment?

#include<stdio.h>

#define STRING "%s\n"
#define NESO "Welcome to Neso Academy!"
// #define NESO Welcome to Neso Academy! creo que no vale
// porque para ser un literal de tipo cadena de caracteres tiene que
// ir entre comillas.

int main(){
    printf(STRING, NESO);
    return 0;
}

// Comentario: lo que se imprime es Welcome to Neso Academy!,
// no "Welcome to Neso Academy!"
// Lo que se hace en este programa es definir dos macros
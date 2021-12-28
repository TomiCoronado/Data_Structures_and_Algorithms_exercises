// C programming (important questions set 1)
// https://www.youtube.com/watch?v=IY79fWYkiPQ&t=11s

// Q1: What is the output of the following C program fragment?

#include<stdio.h>

int main(){
    printf("%d", printf("%s", "Hello world!"));
    return 0;
}

// Comentario: cada uno de los dos printf tiene dos argumentos.
// %s is used to print "string of characters"
// printf not only prints the content on the screen. It also returns the 
// number of characters that it successfully prints on the screen.

// Q2: What is the output of the following C program fragment?

#include<stdio.h>

int main(){
    printf("%10s", "Hello");
    printf("\n");
    printf("%s", "Hello");
    return 0;
}

// Comentario: el segundo printf simplemente imprime Hello, mientras que 
// el primero lo imprime en 10 posiciones pero ajustado a la derecha.

// Q3: What is the output of the following C program fragment?

#include<stdio.h>

int main(){
    // long long int i = 3498;
    char c = 255;
    c = c + 10;
    printf("%d", c);
    // printf("%lld", i);
    return 0;
}

// Posibles respuestas:
// a) 265 -> No, porque se pasa del rango de char, que llega hasta 255 precisamente
// b) Some character according to ASCII table -> No, porque usamos %d no %c
// c) 7 -> No
// d) 9 -> Si   

// Comentario: 265 en binario es 100001001 pero creo que solo nos quedamos con los 
// primeros 8 bits (1byte), es decir, 00001001 = 9. De todos modos creo que esto no
// es del todo así pues la representación de los numeros internamente es en 
// complemento a 2, no como yo la he puesto.

// Q4: Which of the following statements are correct corresponding to the definition
// of integer?

signed int i;
signed i;
unsigned i;
long i;
long int i;
long long i;

// Respuesta: todas son correctas.

// Comentario: las dos primeras son iguales. Y la cuarta y la quinta también son iguales.

// Q5: What is the output of the following C program fragment?

#include<stdio.h>

int main(){
    unsigned i = 1;
    int j = -4;
    printf("%u", i+j);
    return 0;
}

// Posibles respuestas:
// a) garbage
// b) -3
// c) Integer value that depends from machine to machine (respuesta correcta)
// d) None of the above

// Comentario: i + j = -3
//             3 = 00000000 00000000 00000000 00000011
//            -3 = 11111111 11111111 11111111 11111101 (complemento a 2)
// Si imprimo ese -3 con %u se imprimirá el número 4294967293 que ese ese 
// numero binario anterior suponiendo que es un unsigned.
//   Ahora bien, esto es así en mi máquina pero podría no ser así en otra, 
// porque en la mía -3 se representa en binario en formato complemento a 2 (C2)
// y en otra podría ser en magnitud y signo (SM).
//   Bueno, realmente la respuesta que daba el del video es que en mi máquina 
// sizeof(int) es 4 bytes pero en otra podría ser otra cosa.
//   Si hubieramos usado %d sí que se imprime el número -3

/* Program to Check if a given string is Palindrome
Given a string, write a c function to check if it is palindrome or not.
A string is said to be palindrome if reverse of the string is same as 
string. For example, “abba” is palindrome, but “abbc” is not palindrome.
*/

#include<stdio.h>
#include<string.h>  // This headder file contains the prototype of strlen()

/* A function to check if a string str is palindrome*/
void isPalindrome(char str[]){
    int l = 0;
    int h = strlen(str) - 1;
    while (l<h){    // Con recorrer la mitad del string nos basta.
                    // Y basta con que una sola pareja de letras 
                    // no sea igual para que podamos decir que no
                    // palindrome y salir de la funcion.
        if (str[l++] != str[h--]){
            printf("\n %s is not palindrome", str);
            return;
        }
        // Creo que también podríamos poner el l++ y el h-- aqui
        // pero queda más elegante donde lo hemos puesto.
    }
    printf("\n %s is palindrome", str);  // Si en el bucle anterior 
                                      // no se ha producido que 
                                      // ninguna pareja sea diferente
                                      // entonces es palindrome.
}

/* Driver program to test above function*/
int main(){
    isPalindrome("abba");
    isPalindrome("abbccbba");
    isPalindrome("geeks");

    return 0;
}

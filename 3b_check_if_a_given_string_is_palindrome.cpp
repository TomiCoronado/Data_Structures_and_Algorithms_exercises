/*Given a string, write a recursive function that check if the given string
 * is palindrome, else not palindrome.*/

/*The idea of recurstive function is simple:
 * 1) If there is only one character in string return true.
 * 2) Else compare first and last characters and recur for 
 *    remaining substring.*/

// La resolución con el método iterativo la tengo en C y esta en C++
#include<bits/stdc++.h> // En C necesito stdio.h y string.h 
                        // Este último xq llamo a strlen()
// En C no existe el tipo bool pero puedo usar las funciones de abajo si hago esto:
// #include<stdbool.h>
using namespace std;

// A recursive function that
// check a str[s..e] is
// palindrome or not.
bool isPalRec(char str[], int s, int e){
    // If there is only one character
    if (s==e) return true;

    // If first and last characters do not match
    if (str[s]!=str[e]) return false;

    // If there is more than two characters, check if middle substring
    // is also palindrome or not
    if (s<e+1) return isPalRec(str, s+1, e-1);

    return true;
}
// creo que, como hemos puesto un return en cada if, pues no me hace falta 
// ir poniendo else if dado que si un if se cumple salimos de la funcion y 
// el resto no se evaluan

// La anterior función recursiva creo que acaba en el momento en el que devolvemos
// algún return true; o retrun false;

bool isPalindrome(char str[]){
    int n = strlen(str);

    // An empty string is consider Palindrome
    if (n==0) return true;
    return isPalRec(str, 0, n-1);
}

/* Driver program to test above function*/
int main(){
    char str[] = "geeg";

    if (isPalindrome(str))
    cout << "Yes";
    else 
    cout << "No";

    return 0;
}

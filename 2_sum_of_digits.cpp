/* Sum of digits
Given a number, find sum of its digits.
He decidido que el fichero sea con extensión .cpp en vez .c para poder escribir
también la solución usando clases.
*/
#include<iostream>   // C: #include<stdio.h>
using namespace std;   

/* Function 1 to get the sum of digits (iteratively)*/
int getSum1(int n){
    int sum = 0;
    while(n!=0){
        sum = sum + n%10;
        n = n/10;
    }
    /*
      En vez de usar un while podemos resolverlo en una 
    única línea de código con un bucle for:

    for (sum = 0; n > 0; sum += n % 10, n /= 10)
        ;

      Me parece muy interesante que haya puesto ; al final del for.
      Yo estaba acostumbrado a poner un {} vacío si en el for no se hacía nada
    pero esto otro también me parece muy elegante.
    */
    return sum;
}

/* Function 2 to get the sum of digits (iteratively, pero usando una clase)*/
class gfg{
  public:
    int getSum2(int n){
      int sum = 0;
      while(n!=0){
        sum = sum + n%10;
        n = n/10;
      }
      // También aquí podríamos haber usado lo del for de arriba.
      return sum;
    }
};

/* Function 3 to get the sum of digits (con recursividad)*/
int getSum3(int n){
    return n == 0 ? 0 : n % 10 + getSum3(n/10);
}
// Si n es 0 devuelve 0. Si n es 7 no devuelve 0, sino que entra recursivamente 
// en getSum3 porque realiza n % 10 + getSum3(n/10); .Y en esa segunda llamada
// a getSum3, como el argumento es 7/10 = 0, pues devuelve 0.
// Y creo que estas funciones recursivas se analizan así: de final a principio:
// al final retorna 0 pero en la anterior llamada no retornaba 0 sino el resultado
// de hacer n % 10 + getSum3(n/10);

/* Driver code */
int main(){
    gfg g;  // Creo que g es una variable de tipo gfg, que es la clase que hemos
            // definido arriba.
    int n = 687;

    // Usando la Funcion 1:
    printf(" %d ", getSum1(n));
    // Usando la Funión 2:
    cout<<g.getSum2(n);
    // Usando la Funión 3:
    printf(" %d ", getSum3(n));

    return 0;
}

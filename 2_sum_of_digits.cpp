/* Sum of digits
Given a number, find sum of its digits.
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
      It is also possible to solve it with an empty for loop:

    for (sum = 0; n > 0; sum += n % 10, n /= 10)
        ;
    */
    return sum;
}

/* Function 2 to get the sum of digits (iteratively, using a class)*/
class gfg{
    public:
      int getSum2(int n){
        int sum = 0;
        while(n!=0){
          sum = sum + n%10;
          n = n/10;
        }
        // Here is also possible to use the for loop
        return sum;
      }
};

/* Function 3 to get the sum of digits (recursively)*/
int getSum3(int n){
    return n == 0 ? 0 : n % 10 + getSum3(n/10);
}
// If n is 0, it returns 0. If n is 7, it does not return 0, instead it calls
// recursively getSum3, because it computes n % 10 + getSum3(n/10); . In that
// second call to getSum3 it returns 0, since the argument is 7/10 = 0.
// It is conenient to analyse the recursive functions this way: from end to 
// begining. Eventually, it returns 0, but in the previous call it does not 
// return 0, instead it returns the result of n % 10 + getSum3(n/10);

/* Driver code */
int main(){
    gfg g;  // gfg is the defined class
    int n = 687;

    // Using Function 1:
    printf(" %d ", getSum1(n));
    // Using Function 2:
    cout<<g.getSum2(n);
    // Using Function 3:
    printf(" %d ", getSum3(n));
    
    // printf and cout are both used to see the equivalence between them
    return 0;
}

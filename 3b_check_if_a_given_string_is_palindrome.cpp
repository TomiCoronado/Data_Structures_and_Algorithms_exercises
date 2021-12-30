/*Given a string, write a recursive function that check if the given string
 * is palindrome, else not palindrome.*/

/*The idea of recurstive function is simple:
 * 1) If there is only one character in string return true.
 * 2) Else compare first and last characters and recur for 
 *    remaining substring.*/

// Now we are writting the program in C++
#include<bits/stdc++.h> //C: stdio.h and string.h 

// En C we don't have the bool type but can use the funtions below if we include:
// #include<stdbool.h>
using namespace std;

// A recursive function that
// checks a str[s..e] is
// palindrome or not.
bool isPalRec(char str[], int s, int e){
    // If there is only one character
    if (s==e) return true;

    // If first and last characters do not match
    if (str[s]!=str[e]) return false;

    // If there is more than two characters, check if middle substring
    // is also palindrome or not
    if (s<e+1) return isPalRec(str, s+1, e-1);
  
    // We recursively call the function till there is only character 
    // (in that case we return true), or we find a couple of elements 
    // that are not equal (in tath case we return false), or we finish
    // successfully comparing each couple

    return true;
}
// In every recursive funtion its important to identify the recursive process 
// as well as the termination conditions

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

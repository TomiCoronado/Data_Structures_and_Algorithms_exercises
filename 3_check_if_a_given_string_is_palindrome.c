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
    while (l<h){    // We only need to compere the first half of the string 
                    // with the elements in the second half
        if (str[l++] != str[h--]){
            printf("\n %s is not palindrome", str);
            return; // When a couple of elements are not equal we can exit the funtion
        }
        // ++l and --h can also be written here instead of in the if condition
    }
    printf("\n %s is palindrome", str);  // If we haven't exited the funtion from the previous loop,
                                         // then the string is palindrome
}

/* Driver program to test above function*/
int main(){
    isPalindrome("abba");
    isPalindrome("abbccbba");
    isPalindrome("geeks");

    return 0;
}

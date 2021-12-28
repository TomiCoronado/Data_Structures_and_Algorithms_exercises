/* Sum of digits 
Given a number, find sum of its digits.
También he decidido que el fichero tenga extensión .cpp

When the number of digits of that number exceeds 10^19 , we can’t take 
that number as integer since the range of long long int doesn’t satisfy 
the given number. So take input as a string, run a loop from start to the 
length of the string and increase the sum with that character 
(in this case it is numeric)
*/

#include <iostream>     // C: #include<stdio.h>
using namespace std;    // C: sobra esta linea
int getSum(string str)  // C: en C no existe el tipo de dato string sino  
{                       //    el char. By convention, C uses arrays of char 
	int sum = 0;        //    terminated with a null char, i.e., with '\0'.

	// Traversing through the string
	for (int i = 0; i < str.length(); i++) {    // Creo que .length es un method 
		// Since ascii value of                 // que se puede aplicar a strings
		// numbers starts from 48
		// so we subtract it from sum
		sum = sum + str[i] - 48;
	}
	return sum;
}

// Driver Code
int main()
{
	string st = "123456789123456789123422";
	cout << getSum(st);
	return 0;
}

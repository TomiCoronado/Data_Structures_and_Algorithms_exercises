/* Sum of digits 
Given a number, find sum of its digits.

When the number of digits of that number exceeds 10^19 , we can’t take 
that number as integer since the range of long long int doesn’t satisfy 
the given number. So take input as a string, run a loop from start to the 
length of the string and increase the sum with that character 
(in this case it is numeric).
This is an interesting way to store a big number.
*/

#include <iostream>     // C: #include<stdio.h>
using namespace std;    // C: this line is not necessary
int getSum(string str)  // C: By convention, C uses arrays of char 
			//    in C we don't have the string type
	int sum = 0;    // Terminated with a null char, i.e., with '\0'.

	// Traversing through the string
	for (int i = 0; i < str.length(); i++) {    // .length is a usefull method for stings in C++
		// Since ascii value of             
		// numbers starts from 48
		// so we subtract it from sum
		// (str[i] is the ascii the numeration of character i in the ascii table)
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

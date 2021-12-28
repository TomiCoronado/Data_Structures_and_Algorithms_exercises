/* C++ Program to find sum of elements
in a given array */

/*Given a array of integers, find sum of its elements*/
#include<bits/stdc++.h>
using namespace std;

// Function to return sum of elements in an array of size n
int sum(int arr[], int n){
    int sum = 0;
    // Iterate through all elements and add them to sum
    for (int i=0;i<n;i++){
        sum = sum + arr[i];
    }
    return sum;
}

// Driver code 
int main(){
    int arr[] = {12, 3, 4, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Sum of given array is " << sum(arr, n);

    return 0;
}

// Time Complexity: O(n)
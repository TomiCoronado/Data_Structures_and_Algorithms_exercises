/*Write a C/C++ function to return minimum and maximum in an array. Your 
program should make the minimum number of comparisons. */

/*First of all, how do we return multiple values from a C function? 
We can do it either using structures or pointers. 

We have created a structure named pair (which contains min and max) to 
return multiple values.
And the function declaration becomes: struct pair getMinMax(int arr[], int n) 
where arr[] is the array of size n whose minimum and maximum are needed. */

/*METHOD 1 (Simple Linear Search) 
Initialize values of min and max as minimum and maximum of the first two 
elements respectively. Starting from 3rd, compare each element with max and min, 
and change max and min accordingly (i.e., if the element is smaller than min 
then change min, else if the element is greater than max then change max, else 
ignore the element)*/

// C++ program of above implementation
#include<iostream>  // C: #include<stdio.h>
using namespace std;

// Pair struct is used to return two values from getMinMax()
struct Pair{
    int min;
    int max;
};

struct Pair getMinMax_v1(int arr[], int n){
    struct Pair minmax; // This variable is what we return
    int i;

    // If there is only one element then return it as min and max both
    if (n==1){
        minmax.min = arr[0];
        minmax.max = arr[0];
        return minmax;
    }
    // If there are more than one element, then initialize min and max
    // (if the previous if condition wasn't true it means that next 
    // sentences continue to ve executed)
    if (arr[0]>arr[1]){
        minmax.max = arr[0];
        minmax.min = arr[1];
    }
    else{
        minmax.max = arr[1];
        minmax.min = arr[0];
    }

    for (i = 2; i<n;i++){
        if (arr[i]>minmax.max){
            minmax.max = arr[i];
        }
        else if (arr[i]<minmax.min){
            minmax.min = arr[i];
        }
    }
    return minmax;
}

// Driver code
int main(){
    int arr[] = {1000, 11, 445,
                 1, 330, 3000};
    int arr_size = 6;
    
    // Method 1:
    struct Pair minmax = getMinMax_v1(arr, arr_size);

    cout << "Minimum element is "
         << minmax.min << endl;
    cout << "Maximum element is "
         << minmax.max << endl;

    return 0;
}
/*Time Complexity: O(n)

In this method, the total number of comparisons is 1 + 2(n-2) in the worst case 
and 1 + n – 2 in the best case. 
In the above implementation, the worst case occurs when elements are sorted in 
descending order and the best case occurs when elements are sorted in ascending order.*/

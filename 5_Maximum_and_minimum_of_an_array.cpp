/*Write a C/C++ function to return minimum and maximum in an array. Your 
program should make the minimum number of comparisons. */

/*First of all, how do we return multiple values from a C function? 
We can do it either using structures or pointers. 
We have created a structure named pair (which contains min and max) to 
return multiple values.
And the function declaration becomes: struct pair getMinMax(int arr[], int n) 
where arr[] is the array of size n whose minimum and maximum are needed. */

/* METHOD 1 (Simple Linear Search) 
Initialize values of min and max as minimum and maximum of the first two 
elements respectively. Starting from 3rd, compare each element with max and min, 
and change max and min accordingly (i.e., if the element is smaller than min 
then change min, else if the element is greater than max then change max, else 
ignore the element)
Time Complexity: O(n)
In this method, the total number of comparisons is 1 + 2(n-2) in the worst case 
and 1 + n – 2 in the best case. 
In the above implementation, the worst case occurs when elements are sorted in 
descending order and the best case occurs when elements are sorted in ascending order.*/

/* METHOD 2 (Tournament Method) 
Divide the array into two parts and compare the maximums and minimums of the two
parts to get the maximum and the minimum of the whole array.
Pair MaxMin(array, array_size)
    if array_size = 1
        return element as both max and min
    else if arry_size = 2
        one comparison to determine max and min
        return that pair
    else    // array_size  > 2
        recur for max and min of left half
        recur for max and min of right half
        one comparison determines true max of the two candidates
        one comparison determines true min of the two candidates
        return the pair of max and min
Time Complexity: O(n)
Total number of comparisons: let the number of comparisons be T(n). T(n) can be written as follows: 
Algorithmic Paradigm: Divide and Conquer 
    T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2  
    T(2) = 1
    T(1) = 0
If n is a power of 2, then we can write T(n) as: 
    T(n) = 2T(n/2) + 2
After solving the above recursion, we get 
    T(n) = 3n/2 - 2
Thus, the approach does 3n/2 - 2 comparisons if n is a power of 2. And it does more 
than 3n/2 - 2 comparisons if n is not a power of 2.
*/

/* METHOD 3 (Compare in Pairs) 
If n is odd then initialize min and max as first element. 
If n is even then initialize min and max as minimum and maximum of the first two elements respectively. 
For rest of the elements, pick them in pairs and compare their 
maximum and minimum with max and min respectively.
Total number of comparisons: Different for even and odd n, see below: 
    If n is odd:    3*(n-1)/2  
    If n is even:   1 Initial comparison for initializing min and max, 
                           and 3(n-2)/2 comparisons for rest of the elements  
                      =  1 + 3*(n-2)/2 = 3n/2 -2
Second and third approaches make the equal number of comparisons when n is a power of 2. 
In general, method 3 seems to be the best.

(It is 3/2 because we have to check always 3 conditions within the while loop, but the i index 
increments its value by 2 each iteration)
*/

// C++ program of above implementation
#include<iostream>  // C: #include<stdio.h>
using namespace std;

// Pair struct is used to return two values from getMinMax()
struct Pair{
    int min;
    int max;
};

// METHOD 1
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

// METHOD 2
struct Pair getMinMax_v2(int arr[], int low, int high)
{
    struct Pair minmax, mml, mmr;    
    int mid;
     
    // If there is only one element
    if (low == high)
    {
        minmax.max = arr[low];
        minmax.min = arr[low];    
        return minmax;
    }
     
    // If there are two elements
    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        else
        {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }
     
    // If there are more than 2 elements
    mid = (low + high) / 2;
    mml = getMinMax_v2(arr, low, mid);
    mmr = getMinMax_v2(arr, mid + 1, high);
     
    // Compare minimums of two parts
    if (mml.min < mmr.min)
        minmax.min = mml.min;
    else
        minmax.min = mmr.min;    
     
    // Compare maximums of two parts
    if (mml.max > mmr.max)
        minmax.max = mml.max;
    else
        minmax.max = mmr.max;    
     
    return minmax;
}

// METHOD 3
struct Pair getMinMax_v3(int arr[], int n)
{
    struct Pair minmax;    
    int i;
     
    // If array has even number of elements
    // then initialize the first two elements
    // as minimum and maximum
    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])    
        {
            minmax.max = arr[0];
            minmax.min = arr[1];
        }
        else
        {
            minmax.min = arr[0];
            minmax.max = arr[1];
        }
         
        // Set the starting index for loop
        i = 2;
    }
     
    // If array has odd number of elements
    // then initialize the first element as
    // minimum and maximum
    else
    {
        minmax.min = arr[0];
        minmax.max = arr[0];
         
        // Set the starting index for loop
        i = 1;
    }
     
    // In the while loop, pick elements in
    // pair and compare the pair with max
    // and min so far
    while (i < n - 1)
    {        
        if (arr[i] > arr[i + 1])        
        {
            if(arr[i] > minmax.max)    
                minmax.max = arr[i];
                 
            if(arr[i + 1] < minmax.min)        
                minmax.min = arr[i + 1];    
        }
        else       
        {
            if (arr[i + 1] > minmax.max)    
                minmax.max = arr[i + 1];
                 
            if (arr[i] < minmax.min)        
                minmax.min = arr[i];    
        }
         
        // Increment the index by 2 as
        // two elements are processed in loop
        i += 2;
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


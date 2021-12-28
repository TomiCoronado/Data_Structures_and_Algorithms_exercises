/* Reverse an array
Given an array (or string), the task is to reverse the array/string
*/ 
#include<stdio.h> // C++: #include <bits/stdc++.h>
                  //      using namespace std;

/* Function 1 to reverse arr[] from start to end (using a for loop)*/
        // This fuction does not work when s (in main()) is 0
        // It is better to use Functions 2 or 3
void reverseArray1(int arr[], int start, int end){
    int i, arr_aux;
    for(i=start;i<=start+(end-start)/2;i++){
        arr_aux = arr[i];
        arr[i] = arr[end-i];        
        arr[end-i] = arr_aux;
    }
}

/* Function 2 to reverse arr[] from start to end (using a while loop)*/
void reverseArray2(int arr[], int start, int end){
    int arr_aux;
    while(start<end){
        arr_aux = arr[start];
        arr[start] = arr[end];        
        arr[end] = arr_aux;
        start++;
        end--;
    }
}

/* Function 3 to reverse arr[] from start to end (using a recursive function)*/
void reverseArray3(int arr[], int start, int end){
    int arr_aux;
    if(start>=end) return;
    arr_aux = arr[start];
    arr[start] = arr[end];
    arr[end] = arr_aux;
    reverseArray3(arr, start+1, end-1);
}

/* Utility that prints out an array on a line*/
void printArray(int arr[], int size){
    int i;
    for (i=0; i<size; i++) 
        printf("%d ", arr[i]);  
  
    printf("\n");
    /*
    C++:
    for (int i=0; i<size; i++)  
        cout << arr[i] << " ";
 
    cout << endl;
    */ 
}

/* Driver function to test above functions*/
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]); // number of elements, n=6; n-1=5
    int s,e;                            // start and end
    printArray(arr, n);
    printf("Reverse array using Funtion 1: \n");
    s=1;
    e=n-1;
    reverseArray1(arr, s, e);
    printArray(arr, n);
    printf("Reverse array (of the previous reverse array) using Funtion 2: \n");
    reverseArray2(arr, s, e);
    printArray(arr, n);
    printf("Reverse array (of the previous reverse array) using Funtion 3: \n");
    reverseArray3(arr, s, e);
    printArray(arr, n);

    return 0;
}

// This program allows the user to reverse any array form an arbitrary start to 
// an arbitrary end.

// Time complexity es O(n) in each of the three funcions

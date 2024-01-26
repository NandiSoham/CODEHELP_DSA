#include<iostream>
#include<limits.h>
using namespace std;

//-------------------------------------better approach----------------------------------------------------------------------
// void getElements(int arr[], int n){
//     int smallest = INT_MAX, secSmall = INT_MAX;
//     int largest = INT_MIN, secLarge = INT_MIN;

//     for(int i= 0; i < n; i++){
//         smallest = min(smallest, arr[i]);
//         largest = max(largest, arr[i]);
//     }

//     for(int i = 0; i < n; i++){
//         if(n==0 || n==1){
//             cout << -1 << " " << -1 << endl;
//         }

//         if(arr[i] < secSmall && arr[i] != smallest){
//             secSmall = arr[i];
//         }
//         if(arr[i] > secLarge && arr[i] != largest){
//             secLarge = arr[i];
//         }
//     }

//     cout << "Second smallest element is: " << secSmall << endl;
//     cout << "Second largest element is: " << secLarge << endl;
// }

// int main()
// {
//     int arr[] = {1, 2, 4, 6, 7, 5};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     getElements(arr, n);
//     return 0;
// }

//---------------------------------------------------------------------------------

//-------------------------------------optimal approach----------------------------------------------------------------------

int findSecondLargest(int *arr, int n){
    if(n < 2) return -1;
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    for (int i = 0; i < n; i++) {
        if(arr[i] >  largest){
            secondLargest = largest;
            largest = arr[i];
        } else if(arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int findSecondSmallest(int *arr, int n){
    if(n < 2) return -1;
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;
    for(int i = 0; i < n; i++){
        if (arr[i] < smallest){
            secondSmallest = smallest;
            smallest = arr[i];
        } else if(arr[i] < secondSmallest && arr[i] != smallest){
            secondSmallest = arr[i];
        }
    }
    return secondSmallest;
}

int main() {
    int arr[]={1,2,4,7,7,5};  
    int n=sizeof(arr)/sizeof(arr[0]);
    int secondSmallest= findSecondSmallest(arr,n);
    int secondLargest= findSecondLargest(arr,n);
    cout<<"Second smallest is "<<secondSmallest<<endl;
    cout<<"Second largest is "<<secondLargest<<endl;
    return 0;
}
#include<iostream>
#include<limits.h>
using namespace std;

void getElements(int arr[], int n){
    int smallest = INT_MAX, secSmall = INT_MAX;
    int largest = INT_MIN, secLarge = INT_MIN;

    for(int i= 0; i < n; i++){
        smallest = min(smallest, arr[i]);
        largest = max(largest, arr[i]);
    }

    for(int i = 0; i < n; i++){
        if(n==0 || n==1){
            cout << -1 << " " << -1 << endl;
        }

        if(arr[i] < secSmall && arr[i] != smallest){
            secSmall = arr[i];
        }
        if(arr[i] > secLarge && arr[i] != largest){
            secLarge = arr[i];
        }
    }

    cout << "Second smallest element is: " << secSmall << endl;
    cout << "Second largest element is: " << secLarge << endl;
}

int main()
{
    int arr[] = {1, 2, 4, 6, 7, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    getElements(arr, n);
    return 0;
}
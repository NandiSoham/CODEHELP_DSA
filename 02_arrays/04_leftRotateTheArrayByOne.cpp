#include<iostream>
using namespace std;

void rotateArrayByOne(int arr[], int n){
    int temp = arr[0]; // storing the first element of array in a variable
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    rotateArrayByOne(arr, n);
    cout << "after ratating by one the array is: " << endl;
    for(int i = 0; i< n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
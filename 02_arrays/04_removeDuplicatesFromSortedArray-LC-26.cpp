#include<iostream>
using namespace std;

int removeDuplicate(int arr[], int n){
    int i = 0;
    for(int j = 1; j<n; j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}

int main()
{
    int arr[] = {1,1,2,2,2,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = removeDuplicate(arr, n);
    cout << "Array after removing duplicates : ";
    for(int i = 0; i< k; i++){
        cout<< arr[i] << " ";
    }
    return 0;
}
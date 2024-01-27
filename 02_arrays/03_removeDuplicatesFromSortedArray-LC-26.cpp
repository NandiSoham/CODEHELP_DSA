#include<iostream>
#include<set>
using namespace std;

// -----------------------------brute force - >using set--------------------------
int removeDuplicate(int arr[], int n) {
    set < int > set;
    for (int i = 0; i < n; i++) {
        set.insert(arr[i]);
    }
    int k = set.size();
    int j = 0;
    for (int x: set) {
        arr[j++] = x;
    }
    return k;
}

//--------------------------------------------------------------------------------

// -----------------------------optimal approach - >using two pointers--------------------------

int removeDuplicateOptimalApproach(int arr[], int n){
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

    cout << endl;

    int x = removeDuplicateOptimalApproach(arr, n);
    cout << "Array after removing duplicates using two pointers : ";
    for(int i = 0; i< x; i++){
        cout<< arr[i] << " ";
    }
    return 0;
}
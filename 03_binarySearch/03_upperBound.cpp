#include<iostream>
#include<vector>
using namespace std;

//-------------------------BRUT FORCE (Linear Search) ---------------------------------------

int upperBoundBrute(vector<int> &arr, int n, int target){
    for(int i=0; i<n; i++){
        if(arr[i] > target) return i;
    }
    return n;
}

//-------------------------------------------------------------------------------------------

int main()
{
    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int n = 5, target = 9;

    int upperBoundIndexBrute = upperBoundBrute(arr, n, target);
    cout << "The upper bound index is: " << upperBoundIndexBrute   << endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

//-------------------------BRUT FORCE (Linear Search) ---------------------------------------

int lowerBoundBrute(vector<int> &arr, int n, int target){
    for(int i=0; i<n; i++){
        if(arr[i] >= target) return i;
    }
    return n;
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, target = 9;

    int lowerBoundIndexBrute = lowerBoundBrute(arr, n, target);
    cout << "The lower bound index is: " << lowerBoundIndexBrute   << endl;
    return 0;
}
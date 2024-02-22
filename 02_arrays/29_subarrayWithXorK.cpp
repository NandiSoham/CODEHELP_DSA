#include<iostream>
#include<vector>
using namespace std;

//-----------------------------BRUTE FORCE-----------------------------------

int subarraysWithXorK(vector<int> &arr, int k){
    int n = arr.size();
    int count  = 0;
     for(int i = 0; i < n; i++){
        int xorResult = 0;
        for(int j = i; j < n; j++){
            xorResult = xorResult ^ arr[j];
            if(xorResult == k) count++;
        }
     }
     return count;
}

//----------------------------------------------------------------

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(arr, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

//----------------------------- BRUTE FORCE--------------------------------

int longestSubarray(vector<int> &arr, int k){
    int n = arr.size();
    int maxLen = 0;
    for(int i = 0; i < n ; i++){
        int totalSum = 0;
        for(int j = i; j < n; j++){
            totalSum += arr[j];

            if(totalSum == k){
                maxLen = max(maxLen, j-i+1);
            }
        }
    }

    return maxLen;
}

//---------------------------------------------------------------------------------



int main()
{
    vector<int> arr{2,3,5,1,9};
    int k = 10;
    int ansLength = longestSubarray(arr, k);
    cout << "the length of the longest subarray is: " << ansLength <<endl;
    return 0;
}
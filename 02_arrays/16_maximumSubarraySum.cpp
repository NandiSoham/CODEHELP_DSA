#include<iostream>
using namespace std;

//----------------------------------- BRUTE FORCE --------------------------------

int findMaxSubarraySum(int arr[], int n){
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

//----------------------------------------------------------------------------------

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int ans = findMaxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << ans << endl;
    return 0;
}
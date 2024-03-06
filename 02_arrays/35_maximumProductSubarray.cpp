#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//----------------------BRUTE FORCE------------------------------------------

int findMaxProduct(vector<int> &arr){
    int result = arr[0];
    for(int i = 0; i < arr.size() - 1; i++){
        int product = arr[i];
        for(int j = i + 1; j < arr.size(); j++){
            product *= arr[j];
        }
        result = max(result, product);
    }
    return result;
}

//-----------------------------------------------------------------------

//---------------------------OPTIMAL APPROACH--------------------------------------------

int maxProductOptimalApproach(vector<int>& nums) {
        int result = INT_MIN;
        int pre = 1, suff = 1;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;

            pre *= nums[i];
            suff *= nums[n - i - 1];
            result = max(result, max(pre, suff));
        }
        return result;
    }

//---------------------------------------------------------------------------------

int main(){
    vector<int> arr {1, 2, -3, 0, -4, -5};
    // int result = findMaxProduct(arr);
    int ansOptimal = findMaxProduct(arr);
    // cout << "The maximum product of subarray is: " << result << endl;
    cout << "The maximum product of subarray is: " << ansOptimal << endl;
    return 0;
}
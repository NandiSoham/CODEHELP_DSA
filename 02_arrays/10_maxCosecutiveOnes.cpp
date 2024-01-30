#include<iostream>
#include<vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums){
    int currentCounter = 0;
    int maxi = 0;
    for( int i = 0; i < nums.size(); i++ ){
        if(nums[i] != 0){
            currentCounter++;
            maxi = max(maxi, currentCounter);
        }
        else{
            currentCounter = 0;
        }
    }
    
    return maxi;
}

int main()
{
    vector < int > nums = { 1, 1, 0, 1, 1, 1 };
    int ans = findMaxConsecutiveOnes(nums);
    cout << "The maximum  consecutive 1's are " << ans;
    return 0;
}
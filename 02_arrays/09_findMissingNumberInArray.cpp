#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums, int n) {
        int xor1 = 0;
        for(int  i =1 ; i <= n; i ++){
            xor1 = xor1 ^ i;
        }

        int xor2  = 0;
        for(int i = 0; i < n; i++){
            xor2 = xor2 ^ nums[i];
        }

        return xor1 ^ xor2;
    }

int main()
{
    vector <int> nums{1, 2, 4, 5};
    int n = nums.size();
    int ans = missingNumber(nums, n);
    cout << "The missing number is: "<< ans << endl;
    return 0;
}
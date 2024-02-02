#include<iostream>
#include <unordered_map>
#include<vector>
using namespace std;

//--------------------------------------- BRUTE FORCE-------------------------------

vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        for(int i = 0; i <nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                if(nums[i] + nums[j] == target && i != j){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return{-1, -1};
    }

//--------------------------------------------------------------------------

//----------------------------Better Approach---------------------------------

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mpp;
    for(int i = 0; i < nums.size(); i++){
        int element = nums[i];
        int anotherElement = target - element;
        if(mpp.find(anotherElement) != mpp.end()){
            return{mpp[anotherElement], i};
        }
        mpp[element] = i;
    }
    return {-1, -1};
}

int main()
{
    vector <int> arr{2,7,9,13, 8};
    int target = 9;
    vector<int> ans = twoSum(arr, target);
    cout << "the indices are: [" << ans[0] << ", "
         << ans[1] << "]" << endl;
    return 0;
}
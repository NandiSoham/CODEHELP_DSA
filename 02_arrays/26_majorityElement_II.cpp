#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

//------------------------ BRUTE FORCE-------------------------------

vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(ans.size() == 0 || ans[0] != nums[i]){
                int count = 0;

                for(int j = 0; j < n; j++){
                    if(nums[j] == nums[i]){
                        count++;
                    }
                }
                if(count > (n/3)){
                    ans.push_back(nums[i]);
                }
            }
            if (ans.size() == 2) break;
        }
        return ans;
    }
//----------------------------------------------------------------

//---------------------------BETTER APPROACH----------------------

vector<int> majorityElementBetterApproach(vector<int>& nums) {
    int n = nums.size();
        int mini = (n/3) + 1;
        unordered_map<int, int> mpp;
        vector<int> ans;

        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;

            if(mpp[nums[i]] == mini){
                ans.push_back(nums[i]);
            }
            if(ans.size() > 2) break;
        }
        return ans;
}

//----------------------------------------------------------------

int main()
{
    vector<int> arr {11, 22, 11, 22, 11, 22, 33, 33};
    // vector<int> ans = majorityElement(arr);
    vector<int> ans2 = majorityElementBetterApproach(arr);
    cout << "The majority elements are: " << endl;
    for(auto it : ans2){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
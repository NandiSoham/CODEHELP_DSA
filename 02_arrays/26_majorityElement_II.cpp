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

//------------------------OPTIMAL APPROACH------------------------
vector<int> majorityElementOptimalApproach(vector<int>& nums) {
        int n = nums.size();
        int counter1 = 0, counter2 = 0;
        int element1 = INT_MIN, element2 = INT_MIN;

        for(int i = 0; i < n; i++){
            if(counter1 == 0 && nums[i] != element2){
                counter1 = 1;
                element1 = nums[i];
            } else if(counter2 == 0 && nums[i] != element1){
                counter2 = 1;
                element2 = nums[i];
            } else if(nums[i] == element1) counter1++;
            else if(nums[i] == element2) counter2++;
            else counter1--, counter2--;
        }

        //manually check
        int appearedCount1 = 0, appearedCount2 = 0;
        vector<int> ans;
        int mini = (n/3) + 1;
        for(int i = 0; i < n; i++){
            if(nums[i] == element1) appearedCount1++;
            if(nums[i] == element2) appearedCount2++;
        }
        if(appearedCount1 >= mini) ans.push_back(element1);
        if(appearedCount2 >= mini) ans.push_back(element2);
        return ans;
    }

//----------------------------------------------------------------

int main()
{
    vector<int> arr {11, 22, 11, 22, 11, 22, 33, 33};
    // vector<int> ans = majorityElement(arr);
    // vector<int> ans2 = majorityElementBetterApproach(arr);
    vector<int> ans3 = majorityElementOptimalApproach(arr);
    cout << "The majority elements are: " << endl;
    for(auto it : ans3){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
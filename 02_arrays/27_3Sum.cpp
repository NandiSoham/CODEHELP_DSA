#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// ---------------------------BRUTE FORCE------------------------------

vector<vector<int>> threeSumBruteForce(vector<int> &arr) {
    set<vector<int>> st;
    int n = arr.size();

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(arr[i] + arr[j] + arr[k] == 0){
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end()); // Sorting the elements in ascending order to avoid duplicate triplets
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> result(st.begin(), st.end());
    return result;
}

//----------------------------------------------------------------

//---------------------------- BETTER APPROACH(using Hashing)-----------

vector<vector<int>> threeSumBetterApproach(vector<int>& nums) {
        int n = nums.size();
        set <vector<int>> st;

        for(int i = 0; i < n; i++){
            set <int> hashset;
            for(int j = i+1; j < n; j++){
                int thirdElement = -(nums[i] + nums[j]);
                if(hashset.find(thirdElement) != hashset.end()){
                    vector<int> temp = {nums[i], nums[j], thirdElement};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

//----------------------------------------------------------------

//----------------------OPTIMAL APPROACH---------------------------

vector<vector<int>> threeSumOptimalApproach(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums. end());

        for(int i = 0; i < n; i++){
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = n - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0) k--;
                else if(sum < 0) j++;
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }

//----------------------------------------------------------------


int main()
{
    vector<int> arr = { 2, 0, -2, 1, -1, -2, 0, 4, -2, 6, -3, -3};
    int n = arr.size();
    // vector<vector<int>> ans = threeSumBruteForce(arr);
    // vector<vector<int>> ans2 = threeSumBruteForce(arr);
    vector<vector<int>> ans3 = threeSumOptimalApproach(arr);
    for (auto it : ans3) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
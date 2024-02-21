#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// ---------------------------BRUTE FORCE------------------------------

vector<vector<int>> threeSumBruteForce(int n, vector<int> &arr) {
    set<vector<int>> st;
    
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



int main()
{
    vector<int> arr = { 2, 0, -2, 1, -1, -2, 0, 4, -2};
    int n = arr.size();
    // vector<vector<int>> ans = threeSumBruteForce(n, arr);
    vector<vector<int>> ans2 = threeSumBruteForce(n, arr);
    for (auto it : ans2) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
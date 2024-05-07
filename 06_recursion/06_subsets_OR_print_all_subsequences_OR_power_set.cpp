#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int>& nums, int i, vector<int>& tempArr, vector<vector<int>>& ans){
    if(i >= nums.size()){
        ans.push_back(tempArr);
        return;
    }

    tempArr.push_back(nums[i]);
    solve(nums, i+1, tempArr, ans);

    tempArr.pop_back( );
    solve(nums, i+1, tempArr, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> tempArr;

    solve(nums, 0, tempArr, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = subsets(nums);

    cout << "All subsets are:\n";
    for (const auto& subset : result) {
        cout << "[";
        for (int i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i != subset.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]\n";
    }

    return 0;
}

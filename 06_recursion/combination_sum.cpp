#include <iostream>
using namespace std;
#include<vector>
class Solution
{
public:
    void findCombinations(int idx, vector<int> &candidates, int target,
                          vector<vector<int>> &result,
                          vector<int> &combination)
    {
        if (idx == candidates.size())
        {
            if (target == 0)
            {
                result.push_back(combination);
            }
            return;
        }

        // pick
        if (candidates[idx] <= target)
        {
            combination.push_back(candidates[idx]);
            findCombinations(idx, candidates, target - candidates[idx], result,
                             combination);
            combination.pop_back();
        }

        // not pick
        findCombinations(idx + 1, candidates, target, result, combination);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> combination;
        findCombinations(0, candidates, target, result, combination);
        return result;
    }
};

int main()
{
    Solution obj;
    vector<int> v{2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = obj.combinationSum(v, target);
    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void findCombination(int idx, string& digits, string& temp,
                         unordered_map<char, string>& numToLetterMap,
                         vector<string>& ans) {
        if (idx >= digits.length()) {
            ans.push_back(temp);
            return;
        }

        char currChar = digits[idx];
        string str = numToLetterMap[currChar];

        for (int i = 0; i < str.length(); i++) {
            temp.push_back(str[i]);
            findCombination(idx + 1, digits, temp, numToLetterMap, ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
            return {};
        vector<string> ans;
        string temp = "";
        unordered_map<char, string> numToLetterMap;
        numToLetterMap['2'] = "abc";
        numToLetterMap['3'] = "def";
        numToLetterMap['4'] = "ghi";
        numToLetterMap['5'] = "jkl";
        numToLetterMap['6'] = "mno";
        numToLetterMap['7'] = "pqrs";
        numToLetterMap['8'] = "tuv";
        numToLetterMap['9'] = "wxyz";

        findCombination(0, digits, temp, numToLetterMap, ans);

        return ans;
    }
};

int main() {
    Solution solution;
    string digits = "23"; // Example input
    vector<string> combinations = solution.letterCombinations(digits);

    cout << "Letter Combinations of " << digits << " are:\n";
    for (const string& combination : combinations) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}

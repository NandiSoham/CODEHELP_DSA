#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(string &currStr, int n, int openCount, int closeCount,
           vector<string> &ans)
{
    if (currStr.length() == 2 * n)
    {
        ans.push_back(currStr);
        return;
    }

    if (openCount < n)
    {
        currStr.push_back('(');
        solve(currStr, n, openCount + 1, closeCount, ans);
        currStr.pop_back();
    }

    if (closeCount < openCount)
    {
        currStr.push_back(')');
        solve(currStr, n, openCount, closeCount + 1, ans);
        currStr.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    int openCount = 0;
    int closeCount = 0;
    string currStr = "";
    vector<string> ans;

    solve(currStr, n, 0, 0, ans);

    return ans;
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<string> result = generateParenthesis(n);
    cout << "Generated Parentheses:" << endl;
    for (const string &s : result)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}

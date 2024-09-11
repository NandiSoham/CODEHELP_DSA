#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int n = bills.size();
        int changeFive = 0, changeTen = 0;

        for (int i = 0; i < n; i++)
        {
            if (bills[i] == 5)
                changeFive++;
            else if (bills[i] == 10)
            {
                if (changeFive > 0)
                {
                    changeFive--;
                    changeTen++;
                }
                else
                    return false;
            }
            else
            {
                if (changeFive > 0 && changeTen > 0)
                {
                    changeFive--;
                    changeTen--;
                }
                else if (changeFive >= 3)
                    changeFive -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> bills = {5, 5, 5, 10, 20};
    cout << "Queues of customers: ";
    for (int bill : bills)
    {
        cout << bill << " ";
    }
    cout << endl;
    Solution solution;
    bool ans = solution.lemonadeChange(bills);
    if (ans)
        cout << "It is possible to provide change for all customers." << endl;
    else
        cout << "It is not possible to provide change for all customers." << endl;
    return 0;
}

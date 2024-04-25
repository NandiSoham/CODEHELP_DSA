#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        long ans = 0;

        if(s.length() == 0) return 0;
        int i = 0;
        while(i < s.size() && s[i] == ' ') i++;
        s = s.substr(i);

        if(s[0] == '-') sign = -1;

        i = (s[0] == '-' || s[0] == '+') ? 1 : 0;
        while(i < s.length()){
            if(s[i] == ' ' || !isdigit(s[i])) break;
            ans = ans * 10 + (s[i] - '0');

            if(sign == -1 && sign*ans < INT_MIN) return INT_MIN;
            if(sign == 1 && sign*ans > INT_MAX) return INT_MAX;
            i++;
        }
        return (int)(sign*ans);
    }
};

int main() {
    Solution solution;

    string test1 = "42";
    string test2 = "   -42";
    string test3 = "4193 with words";
    string test4 = "words and 987";
    string test5 = "-91283472332";

    cout << "Test 1: " << solution.myAtoi(test1) << endl;
    cout << "Test 2: " << solution.myAtoi(test2) << endl;
    cout << "Test 3: " << solution.myAtoi(test3) << endl;
    cout << "Test 4: " << solution.myAtoi(test4) << endl;
    cout << "Test 5: " << solution.myAtoi(test5) << endl;

    return 0;
}

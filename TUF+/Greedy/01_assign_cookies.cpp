#include <bits/stdc++.h>
using namespace std;

class Solution{    
    public:
    int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
        int m = Student.size();
        int n = Cookie.size();
        int leftPtr = 0, rightPtr = 0;

        sort(Student.begin(), Student.end());
        sort(Cookie.begin(), Cookie.end());

        while(leftPtr < m && rightPtr < n){
            if(Cookie[rightPtr] >= Student[leftPtr]){
                leftPtr++;
            }
            rightPtr++;
        }

        return leftPtr;
    }
};

int main() {
    // Example input
    vector<int> Student = {1, 2};
    vector<int> Cookie = {1, 2, 3};

    // Create a Solution object
    Solution solution;

    // Call the findMaximumCookieStudents function
    int result = solution.findMaximumCookieStudents(Student, Cookie);

    // Output the result
    cout << "Number of students satisfied: " << result << endl;

    return 0;
}
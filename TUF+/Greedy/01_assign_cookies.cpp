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
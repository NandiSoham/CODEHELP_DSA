#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//----------------------------BRUTE FORCE------------------------------------

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size();
    
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) { 
        int start = arr[i][0];
        int end = arr[i][1];

        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

//----------------------------------------------------------------

//---------------------OPTIMAL APPROACH-------------------------------------------

vector<vector<int>> mergeOptimal(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            } else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }

        }
        return ans;
    }

//----------------------------------------------------------------

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    vector<vector<int>> ans2 = mergeOptimal(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans2) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}



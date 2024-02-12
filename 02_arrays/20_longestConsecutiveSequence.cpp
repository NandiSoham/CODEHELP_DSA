#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//---------------------------------BRUTE FORCE------------------------------

bool linearSearch(vector<int> &arr, int num){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] == num) return true;
    }
    return false;
}

int longestConsecutive(vector<int> &arr){
    int n = arr.size();
    int longest = 1;

    for(int i = 0; i < n; i++){
        int x  = arr[i];
        int cnt = 1;

        while(linearSearch(arr, x+1) == true){
            x += 1;
            cnt += 1;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

//----------------------------------------------------------------

//--------------------------BETTER APPROACH--------------------------------------

int longestConsecutiveSequence(vector<int> &arr){
    if(arr.size() == 0) return 0;

    sort(arr.begin(), arr.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] - 1 == lastSmaller){
            lastSmaller = arr[i];
            cnt += 1;
        } else if(arr[i] != lastSmaller){
            cnt = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}

//----------------------------------------------------------------

int main()
{
    vector<int> arr = {100, 200, 1, 2, 3, 4};
    int ans = longestConsecutive(arr);
    int ans2 = longestConsecutiveSequence(arr);
    cout << "The length of the longest consecutive elements is: " << ans << endl;
    cout << "Using better  approach, The length of the longest consecutive elements is: " << ans2 << endl;
    return 0;
}
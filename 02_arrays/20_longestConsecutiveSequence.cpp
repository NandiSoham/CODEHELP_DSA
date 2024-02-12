#include <iostream>
#include <vector>
using namespace std;

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

int main()
{
    vector<int> arr = {100, 200, 1, 2, 3, 4};
    int ans = longestConsecutive(arr);
    cout << "The length of the longest consecutive elements is: " << ans << endl;
    return 0;
}
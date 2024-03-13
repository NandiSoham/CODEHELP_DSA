#include<iostream>
#include<vector>
using namespace std;

//-------------------------BRUT FORCE (Linear Search) ---------------------------------------

int lowerBoundBrute(vector<int> &arr, int n, int target){
    for(int i=0; i<n; i++){
        if(arr[i] >= target) return i;
    }
    return n;
}

//---------------------------------------------------------------------------------------

//-----------------------------OPTIMAL (Binary Search) -----------------------------------

int lowerBoundOptimal(vector<int> arr, int n, int x) {
	// Write your code here
	int low = 0, high = n - 1;
	int ans = n;
	while(low<= high){
		int mid = low + (high - low)/2;

		if(arr[mid] >= x){
			ans = mid;
			high = mid -1;
		} else{
			low = mid + 1;
		}
	}
	return ans;
}

//---------------------------------------------------------------------------------------------

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, target = 15;

    // int lowerBoundIndexBrute = lowerBoundBrute(arr, n, target);
    int lowerBoundIndexOptimal = lowerBoundOptimal(arr, n, target);
    cout << "The lower bound index is: " << lowerBoundIndexOptimal   << endl;
    return 0;
}
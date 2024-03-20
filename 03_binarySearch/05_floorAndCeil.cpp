#include<iostream>
#include<vector>
using namespace std;

int findCeil(vector<int> &a, int n, int x){
	int ans = -1;
	int low = 0, high = n - 1;

	while(low <= high){
		int mid = low + (high - low)/2;
		if(a[mid] >= x){
			ans = a[mid];
			high = mid - 1;
		} else low = mid + 1;
	}
	return ans;
}

int findFloor(vector<int> &a, int n, int x){
	int ans = -1;
	int low = 0, high = n - 1;

	while(low <= high){
		int mid = low + (high - low)/2;
		if(a[mid] <= x){
			ans = a[mid];
			low = mid + 1;
		} else high = mid - 1;
	}
	return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {

	int floor_element = findFloor(a, n, x);
	int ceil_element = findCeil(a, n, x);

	return make_pair(floor_element, ceil_element);
}

using namespace std;
int main()
{
    vector<int> arr = {3, 4, 4, 7, 8, 10};
	int n = 6, x = 5;
	pair<int, int> ans = getFloorAndCeil(arr, n, x);
	cout << "The floor and ceil are: " << ans.first << " " << "and " << ans.second << endl;
	return 0;
}
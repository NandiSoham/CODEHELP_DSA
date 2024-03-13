#include <iostream>
#include <vector>
using namespace std;

//-------------------------BRUT FORCE (Linear Search) ---------------------------------------

int upperBoundBrute(vector<int> &arr, int n, int target)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > target)
			return i;
	}
	return n;
}

//-------------------------------------------------------------------------------------------

//---------------------------OPTIMAL APPROACH (Binary Search)--------------------------------

int upperBoundOptimal(vector<int> &arr, int x, int n)
{

	int low = 0, high = n - 1;
	int ans = n;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] > x)
		{
			ans = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return ans;
}

//------------------------------------------------------------------------------------------

int main()
{
	vector<int> arr = {3, 5, 8, 9, 15, 19};
	int n = 5, target = 3;

	// int upperBoundIndexBrute = upperBoundBrute(arr, n, target);
	int upperBoundIndexOptimal = upperBoundOptimal(arr, n, target);

	cout << "The upper bound index is: " << upperBoundIndexOptimal << endl;
	return 0;
}
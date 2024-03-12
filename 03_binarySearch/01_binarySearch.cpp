#include <iostream>
#include <vector>
using namespace std;

//----------------------------Iterative Way------------------------------------

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

//----------------------------------------------------------------

//---------------------- Recursive Way --------------------------------

int binarySearch(vector<int> &nums, int low, int high, int target)
{

    // base case
    if (low > high)
        return -1;

    // perform recursion
    int mid = low + (high - low) / 2;
    if (nums[mid] == target)
        return mid;
    else if (nums[mid] < target)
        return binarySearch(nums, mid + 1, high, target);
    else
        return binarySearch(nums, low, mid - 1, target);
}

int searchRecursiveWay(vector<int> &nums, int target)
{
    return binarySearch(nums, 0, nums.size() - 1, target);
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 9;
    // int ind = search(a, target);
    int ans = searchRecursiveWay(a, target); 
    if (ans == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: " << ans << endl;
    return 0;
}
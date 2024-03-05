#include <iostream>
#include <vector>
using namespace std;

//-----------------------BRUTE FORCE-----------------------------------------

int countPairs(vector<int> &a, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > 2 * a[j])
                cnt++;
        }
    }
    return cnt;
}

//----------------------------------------------------------------

//---------------------------OPTIMAL APPROACH-------------------------------------

int countPairs(vector<int> &nums, int low, int mid, int high)
{
    int right = mid + 1;
    int count = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && (long long)nums[i] > 2LL * nums[right])
            right++;
        count += (right - (mid + 1));
    }
    return count;
}

void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
}

int mergeSort(vector<int> &nums, int low, int high)
{
    int count = 0;
    int mid = (low + high) / 2;
    if (low >= high)
        return count;

    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid + 1, high);
    count += countPairs(nums, low, mid, high);

    merge(nums, low, mid, high);
    return count;
}

int reversePairs(vector<int> &nums, int n)
{
    return mergeSort(nums, 0, n - 1);
}

// ----------------------------------------------------------------

int main()
{
    vector<int> a = {2, 4, 3, 5, 1};
    int n = 5;
    // int cnt = countPairs(a, n);
    int ans = reversePairs(a, n);
    cout << "The number of reverse pair is: " << ans << endl;
    return 0;
}

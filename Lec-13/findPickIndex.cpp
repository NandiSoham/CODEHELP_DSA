#include <iostream>
#include <vector>
using namespace std;

int pickIndex(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}

int main()
{
    int arr[4] = {0, 10, 25, 2};
    cout << "pick is: " << pickIndex(arr, 4);
}
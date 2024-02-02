#include<iostream>
#include<vector>
using namespace std;

void sortArray(vector<int> &arr, int n){
    int count_0 = 0, count_1 = 0, count_2 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0) count_0++;
        else if(arr[i] == 1) count_1++;
        else count_2++;
    }

    for(int i = 0; i < count_0; i++) arr[i] = 0;
    for(int i = count_0; i < count_0 + count_1; i++) arr[i] = 1;
    for(int i = count_0 + count_1; i < n; i++) arr[i] = 2;
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
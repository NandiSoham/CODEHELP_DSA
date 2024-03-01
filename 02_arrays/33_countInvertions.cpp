#include<iostream>
#include<vector>
using namespace std;

//------------------------Brute Force----------------------------------------

int numberOfInvertions(vector<int>&arr, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]) count++;
        }
    }
    return count;
}

//----------------------------------------------------------------

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = 5;
    int ans = numberOfInvertions(arr, n);
    cout << "Number of inverted pairs are: "<< ans << endl;

    return 0;
}
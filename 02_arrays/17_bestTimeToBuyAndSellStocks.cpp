#include<iostream>
#include<vector>
using namespace std;

int findMaxProfit(vector <int> &arr){
    int maxProfit = 0;
    for(int i = 0; i < arr.size(); i++){
        for(int j = i+1; j < arr.size();j++){
            if(arr[j] > arr[i]){
                maxProfit = max(maxProfit, arr[j] - arr[i]);
            }
        }
    }

    return maxProfit;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = findMaxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}
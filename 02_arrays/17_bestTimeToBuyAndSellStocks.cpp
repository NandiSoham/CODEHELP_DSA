#include<iostream>
#include<vector>
using namespace std;

//--------------------------------------Approach -1 -----------------------------------
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

//------------------------------------------------------------------------------------

// Approach -1 might give Time Limit Exceed(TLE) error

//--------------------------Approach -2 --------------------------------
int findMaxProfit(vector<int>& prices) {
        int maxProfitAmount = 0;
        int minPrice = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            minPrice = min(prices[i], minPrice);
            maxProfitAmount = max(maxProfitAmount, prices[i] - minPrice);
        }

        return maxProfitAmount;
    }

//----------------------------------------------------------------

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = findMaxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}
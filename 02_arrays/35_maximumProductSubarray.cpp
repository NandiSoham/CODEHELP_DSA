#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int findMaxProduct(vector<int> &arr){
    int result = arr[0];
    for(int i = 0; i < arr.size(); i++){
        int product = arr[i];
        for(int j = i + 1; j < arr.size(); j++){
            product *= arr[j];
        }
        result = max(result, product);
    }
    return result;
}

int main(){
    vector<int> arr {2, 3, -6, 5, 7, 8, -1, 9};
    int result = findMaxProduct(arr);
    cout << "The maximum product of subarray is: " << result << endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

//----------------------------BRUTE FORCE----------------------------------

int getSingleElement(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int count = 0;
        int num = arr[i];

        for(int j = 0; j < n; j++){
            if(arr[j] == num){
                count++;
            }
            if(count == 1) return num;
        }
    }
    return -1;

}

//--------------------------------------------------------------------------------------------

//-----------------------------------OPTIMAL - using XOR ---------------------------------------------

int getSingleElement(vector<int> &arr){
    int xorResult = 0;
    int n = arr.size();

    for(int i = 0; i < n; i++){
        xorResult = xorResult ^ arr[i];
    }
    return xorResult;
}

//------------------------------------------------------------------------------------------------------

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}
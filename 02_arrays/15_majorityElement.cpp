#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

//------------------------------BRUTE FORCE---------------------------------

// int findMajorityElement(vector<int> &arr){
//     int n = arr.size();
//     for(int i = 0; i < n; i++){
//         int count = 0;
//         for(int j = 0; j < n; j++){
//             if(arr[j] == arr[i]){
//                 count++;
//             }
//         }
//         if(count > (n / 2)) return arr[i];
//     }
//     return -1;
// }

//-------------------------------------------------------------------------------

//--------------------BETTER APPROACH -> using HASHING---------------------------

// int findMajorityElement(vector<int> &arr){
//     unordered_map<int, int> mpp;

//     for(int i = 0; i < arr.size(); i++){
//         mpp[arr[i]]++;
//     }

//     for(auto it: mpp){
//         if(it.second > (arr.size()/2)){
//             return it.first;
//         }
//     }

//     return -1;
// }

//-----------------------------------------------------------------------------

//------------------------OPTIMAL APPROACH -> Moore’s Voting Algorithm -------------------
int findMajorityElement(vector<int>& nums) {
        int element;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                count = 1;
                element = nums[i];
            } else if(nums[i] == element) count++;
            else count--;
        }

        int appearedCount = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == element) appearedCount++;
            if(appearedCount > nums.size()/2){
                return element;
            }
        }

        return -1;
    }

//--------------------------------------------------------------------------------------

int main()
{
    vector<int> arr {2,2,1,3,2,3,2};
    int majorityElement = findMajorityElement(arr);
    cout << "The majority element that appears more than n/2 times is: " << majorityElement << endl;
    return 0;
}
#include <iostream>
#include<vector>
using namespace std;
void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        for(int i = 0; i < nums.size(); i++){
            temp[(i+k)% nums.size()] = nums[i];
        }

        nums = temp;
    }
int main()
{
  vector<int> nums = {1,2,3,4,5,6,7};
  int k = 3;
  rotate(nums, k);
  cout << "After Rotating the k elements to left ";
  for (int i = 0; i < nums.size(); i++)
    cout << nums[i] << " ";
  cout << endl;
  return 0;
}
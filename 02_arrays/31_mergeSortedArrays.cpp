#include<iostream>
#include<vector>
using namespace std;

void mergeArrayBruteForce(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int left = 0, right = 0, index = 0;
        vector<int> nums3(n+m, 0);

        while(left < n && right < m){
            if(nums1[left] <= nums2[right]){
                nums3[index] = nums1[left];
                left++, index++;
            } else{
                nums3[index] = nums2[right];
                right++, index++;
            }
        }

        while(left< n){
            nums3[index++] = nums1[left];
        }

        while(right < m){
            nums3[index++] = nums2[right++];
        }

        for(int i = 0; i < n + m; i++){
            if(i < n) nums1[i] = nums3[i];
            else nums2[i - n] = nums3[i];
        }

    }

int main()
{
    vector<int> nums1{1, 4, 8, 10};
    vector<int> nums2{2, 3, 9};
    int n = 4, m = 3;
    
    mergeArrayBruteForce(nums1, n, nums2, m);
    cout << "The merged arrays are: " << "\n";
    cout << "nums1[] = ";
    for (int i = 0; i < n; i++) {
        cout << nums1[i] << " ";
    }
    cout << "\nnums2[] = ";
    for (int i = 0; i < m; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl;
    return 0;

}
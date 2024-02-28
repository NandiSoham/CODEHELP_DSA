#include<iostream>
#include<vector>
using namespace std;

//-----------------------BRUTE FORCE -----------------------------------------

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

//----------------------------------------------------------------

//-----------------------APPROACH 2 (GAP)-----------------------------------------

void swapIfGreater(vector<int>& nums1, int ind1, vector<int>& nums2, int ind2) {
    if (nums1[ind1] > nums2[ind2]) {
        swap(nums1[ind1], nums2[ind2]);
    }
}

void mergeUsingGap(vector<int>& nums1, int n, vector<int>& nums2, int m) {
    // len of the imaginary single numsay:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in nums1[]
            //and right in nums2[]:
            if (left < n && right >= n) {
                swapIfGreater(nums1, left, nums2, right - n);
            }
            // case 2: both pointers in nums2[]:
            else if (left >= n) {
                swapIfGreater(nums2, left - n, nums2, right - n);
            }
            // case 3: both pointers in nums1[]:
            else {
                swapIfGreater(nums1, left, nums1, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}

//----------------------------------------------------------------

int main()
{
    vector<int> nums1{1, 4, 8, 10};
    vector<int> nums2{2, 3, 9};
    int n = 4, m = 3;
    
    // mergeArrayBruteForce(nums1, n, nums2, m);
    mergeUsingGap(nums1, n, nums2, m);
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
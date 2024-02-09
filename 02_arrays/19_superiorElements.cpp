#include<iostream>
#include<vector>
using namespace std;
//-----------------------------------------BRUTE FORCE---------------------------
vector<int> printLeadersBruteForce(int arr[], int n) {

  vector<int> ans;
  
  for (int i = 0; i < n; i++) {
    bool leader = true;

    for (int j = i + 1; j < n; j++)
      if (arr[j] > arr[i]) {
        leader = false;
        break;
      }
    if (leader)
    ans.push_back(arr[i]);

  }
  
  return ans;
}
//-------------------------------------------------------------------------------------

//---------------------------------Optimal-----------------------------------------------
vector<int> superiorElements(int arr[], int n) {

    vector<int> ans;
    int max = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
        if (arr[i] > max) {
        ans.push_back(arr[i]);
        max = arr[i];
        }

    
    return ans;
}
//------------------------------------------------------------------------------------------

int main() {
    int n = 6;
    int arr[n] = {10, 22, 12, 3, 0, 6};

    // vector<int> ans = printLeadersBruteForce(arr,n);
    vector<int> ans = superiorElements(arr,n);
    for(int i = 0;i<ans.size();i++){
      
        cout<<ans[i]<<" ";
    }
  
    cout<<endl;
    return 0;
}


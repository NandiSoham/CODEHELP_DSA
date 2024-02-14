// leetcode -> 54. Spiral Matrix

#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralPrint(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        vector<int> ans;

        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            for(int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            
        }
        return ans;
    }

int main() {
    
    //Matrix initialization.
    vector<vector<int>> matrix   {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15, 16}};
                                
    vector<int> ans = spiralPrint(matrix);

    for(int i = 0;i<ans.size();i++){
        
        cout<<ans[i]<<" ";
    }
    
    cout<<endl;
    
    return 0;
}
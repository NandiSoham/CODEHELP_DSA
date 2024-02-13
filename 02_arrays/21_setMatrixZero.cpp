#include<iostream>
#include<vector>
using namespace std;

//-----------------------------------BRUTE FORCE------------------------------------------------
void markRow(vector<vector<int>> &matrix, int n, int m, int i){
    for(int j = 0; j < n; j++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &matrix, int n, int m, int j){
    for(int i = 0; i < n; i++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>>& matrix, int n, int m) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

//----------------------------------------------------------------

//-------------------BETTER APPROACH----------------------------------------

vector<vector<int>> zeroMatrixBetterApproach(vector<vector<int>> &matrix, int n, int m){
    int extraRow[n] = {0}; 
    int extraCol[m] = {0};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            if(matrix[i][j] == 0){
                extraRow[i] = 1;
                extraCol[j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(extraRow[i] == 1 || extraCol[j] == 1){
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> matrixBetter = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();

//--------ANSWER SECTION FOR BRUTE FORCE-----------------------------------

    vector<vector<int>> ans = zeroMatrix(matrix, n, m);
    cout << "The Final matrix is: \n";
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
//----------------------------------------------------------------

//---------------------ANSWER SECTION FOR BETTER APPROACH-----------
    vector<vector<int>> ansBetterApproach = zeroMatrixBetterApproach(matrixBetter, n, m);
    cout << "The Final matrix is using better approach: \n";
    for (int i = 0; i < ansBetterApproach.size(); ++i) {
        for (int j = 0; j < ansBetterApproach[i].size(); ++j) {
            cout << ansBetterApproach[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
//----------------------------------------------------------------
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//------------------------------ BRUTE FORCE---------------------------------------------
vector < vector < int >> rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int > (n, 0));
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        rotated[j][n - i - 1] = matrix[i][j];
    }
    }
    return rotated;
}

//------------------------------------------------------------------------

//------------------------------BETTER APPROACH-----------------------------

vector < vector < int >> rotateOptimal(vector < vector < int >> & matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = i; j < m; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    return matrix;
}


int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // vector < vector < int >> rotated = rotate(arr);
    vector < vector < int >> rotatedOptimal = rotateOptimal(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotatedOptimal.size(); i++) {
    for (int j = 0; j < rotatedOptimal[0].size(); j++) {
        cout << rotatedOptimal[i][j] << " ";
    }
    cout << "\n";
    }

}

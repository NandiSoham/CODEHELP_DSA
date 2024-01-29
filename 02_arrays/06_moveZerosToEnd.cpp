#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//----------------------------BRUTE FORCE APPROACH-----------------------
// void moveZeros(std::vector<int>& arr, int n){
//     vector<int> temp;
//     for(int i = 0; i < n; i++){
//         if(arr[i] != 0){
//             temp.push_back(arr[i]);
//         }
//     }

//     for(int i = 0; i < temp.size(); i++){
//         arr[i] = temp[i];
//     }

//     for(int i = temp.size(); i < arr.size(); i++){
//         arr[i] = 0;
//     }
// }
//-----------------------------------------------------------------------------------

//--------------------OPTIMAL APPROACH - TWO POINTERS ----------------------------------------
void moveZeros(std::vector<int>& arr, int n){
        int j = -1;

        // Find the index of the first zero
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                j = i;
                break;
            }
        }

        // If no zero is found, return
        if (j == -1) {
            return;
        }

        // Move non-zero elements to the left
        for (int i = j + 1; i < n; i++) {
            if (arr[i] != 0) {
                swap(arr[j], arr[i]);
                j++;
            }
        }
}
//-----------------------------------------------------------------------------------

int main()
{
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = arr.size();  
    moveZeros(arr, n);  
    for (int i=0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
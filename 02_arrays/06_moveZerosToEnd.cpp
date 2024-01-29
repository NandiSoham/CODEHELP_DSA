#include<iostream>
#include<vector>
using namespace std;

void moveZeros(std::vector<int>& arr, int n){
    vector<int> temp;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }

    for(int i = 0; i < temp.size(); i++){
        arr[i] = temp[i];
    }

    for(int i = temp.size(); i < arr.size(); i++){
        arr[i] = 0;
    }
}

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
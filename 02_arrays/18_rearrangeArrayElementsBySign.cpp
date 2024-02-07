#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeElement(vector<int> & arr){
    vector<int> posElement;
    vector<int> negElement;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > 0) posElement.push_back(arr[i]);
        else negElement.push_back(arr[i]);
    }

    for(int i = 0; i < arr.size()/2; i++){
        arr[2*i] = posElement[i];
        arr[2*i+1] = negElement[i];
    }

    return arr;
}

int main()
{
    vector<int> arr {1,4,-2,7,-6,-1};
    vector<int> ans = rearrangeElement(arr);
    cout << "after rearrange by sign the array is: " << endl;
    for(int i = 0; i < arr.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
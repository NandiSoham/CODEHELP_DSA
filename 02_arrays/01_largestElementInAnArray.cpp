#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int sortArr(vector<int> &arr){

    //----------------brute force------------------
    // sort(arr.begin(),arr.end());
    // return arr[arr.size()-1];
    //------------------------------------------------

    //---------optimal-----------------------------------
    int maxi = arr[0];
    int n = arr.size();
    for(int i = 0; i<n; i++){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
    }
    return maxi;
}

int main()
{
    vector<int> arr1 = {2,5,1,3,0};
    vector<int> arr2 = {8,10,5,7,9};
   
    cout<<"The Largest element in the array is: "<<sortArr(arr1)<<endl;
    cout<<"The Largest element in the array is: "<<sortArr(arr2);
   
    
    return 0;
}
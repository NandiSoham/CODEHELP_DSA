#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeElementSecondVariety(vector<int>&a) {
    // Write your code here.
    int n = a.size();
    vector<int> pos;
    vector<int> neg;

    for(int i= 0; i < n; i++){
        if(a[i] > 0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }

    if (pos.size() > neg.size()){

        for(int i = 0; i < neg.size(); i++){
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        
        int startIndexForRest = neg.size()*2;
        for(int i = neg.size(); i < pos.size(); i++){
            a[startIndexForRest] = pos[i];
            startIndexForRest++;
        }

    } else{
        for(int i = 0; i < pos.size(); i++){
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        
        int startIndexForRest = pos.size()*2;
        for(int i = pos.size(); i < neg.size(); i++){
            a[startIndexForRest] = neg[i];
            startIndexForRest++;
        }
    }
    return a;
    
}

int main()
{
    vector<int> arr {1,4,-2,7,-6,9, 5, 4};
    vector<int> ans = rearrangeElementSecondVariety(arr);
    cout << "after rearrange by sign the array is: " << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//-------------------------BRUTE FORCE - using SET-----------------------------------------

vector < int > unionArray(vector < int >& a, vector < int >& b) {

    set < int > st;
    vector<int> ans;
    int n1 = a.size();
    int n2 = b.size();
    for(int i= 0; i <n1; i++){
        st.insert(a[i]);
    }

    for(int i= 0; i <n2; i++){
        st.insert(b[i]);
    }

    for(auto &it: st){
        ans.push_back(it);
    }
    return ans;
}

//---------------------------------------------------------------------------------------------------------

//------------------------------ Optimal - using two pointers------------------------------------------------------

vector < int > unionArrayUsingTwoPointers(vector < int > a, vector < int > b) {
    // Write your code here
    int n1 = a.size();
    int n2 = b.size();
    int  i = 0, j = 0;
    vector <int> ans;
    
    while(i < n1 && j < n2){
        if(a[i] <= b[j]){
            if(ans.size() == 0 || ans.back() != a[i]){
                ans.push_back(a[i]);
            }
            i++;
        }
        else{
            if(ans.size() == 0 || ans.back() != b[j]){
                ans.push_back(b[j]);
            }
            j++;
        }
    }

    while(i < n1){
            if(ans.size() == 0 || ans.back() != a[i]){
                ans.push_back(a[i]);
            }
            i++;
    }

    while(j < n2){
        if(ans.size() == 0 || ans.back() != b[j]){
                ans.push_back(b[j]);
            }
            j++;
    }

    return ans;
}

//---------------------------------------------------------------------------------------------------------

int main()
{
    vector < int > a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector < int > b{2, 3, 4, 4, 5, 11, 12};
    int n1 = a.size();
    int n2 = b.size();
    vector <int> ans = unionArray(a, b);
    vector <int> ans = unionArrayUsingTwoPointers(a, b);
    cout << "Union of the arrays is : " << endl;
    for(auto & it:ans){
        cout << it << " ";
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

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

int main()
{
    vector < int > a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector < int > b{2, 3, 4, 4, 5, 11, 12};
    int n1 = a.size();
    int n2 = b.size();
    vector <int> ans = unionArray(a, b);
    cout << "Union of the arrays is : " << endl;
    for(auto & it:ans){
        cout << it << " ";
    }
    return 0;
}
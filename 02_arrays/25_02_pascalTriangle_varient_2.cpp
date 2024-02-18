#include<iostream>
using namespace std;

void printNthRow(int n){
    int ans = 1;
    cout << ans << " ";

    for(int i = 1; i < n; i++){
        ans = ans * (n - i);
        ans = ans/ i;
        cout << ans << " ";
    }
}

int main()
{
    int n = 6;
    printNthRow(n);
    return 0;
}
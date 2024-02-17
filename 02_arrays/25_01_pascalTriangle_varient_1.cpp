#include<iostream>
using namespace std;

int nCr (int n, int r){
    long long result = 1;

    for(int i = 0; i < r; i++){
        result = result * (n - i);
        result = result / (i + 1);
    }
    return result;
}

int pascalTriangleElement(int r, int c){
    int element = nCr(r - 1, c - 1);
    return element;
}

int main()
{
    int r = 7;
    int c = 4;
    int element = pascalTriangleElement(r, c);
    cout << "The element at position (r,c) is " << element << endl;
    return 0;
}
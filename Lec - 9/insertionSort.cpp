#include <iostream>
using namespace std;

void printArray( int A[], int n){
    for(int i = 0; i< n; i++){
        cout<< A[i]<< " ";
    }
    cout<<endl; 
}

void insertionSort(int A[], int n){
    int key, j;
    //loop for passes
    for(int i = 1; i <= n-1; i++){
        //loop for each pass
        key = A[i];     //A[i] is the element which we'll move
        j = i-1;    
        while(j >= 0 && A[j] > key){
            A[j+1] = A[j]; 
            j--;
        }
        A[j+1] = key;
    }
}

int main(){
    //-1   0   1   2   3   4   5  (index)
    //    12,| 54, 65, 7, 23, 9   (value) i = 1, j= 0, key = 54
    //    12,| 54, 65, 7, 23, 9 -->1st pass done (i = 1)

    //    12, 54,| 65, 7, 23, 9  --> i = 2, j = 1, key = 65
    //    12, 54,| 65, 7, 23, 9  --> 2nd pass done (i = 2)

    //    12, 54, 65,| 7, 23, 9  --> i = 3, j = 2, key = 7
    //    12, 54, 65,| 65, 23, 9 --> i = 3, j = 1, key = 7
    //    12, 54, 54,| 65, 23, 9 --> i = 3, j = 0, key = 7
    //    12, 12, 54,| 65, 23, 9 --> i = 3, j = -1, key = 7
    //    7, 12, 54,| 65, 23, 9 --> i = 3, j = -1, key = 7 --> 3rd pass done(i = 3)
    
    //    7, 12, 54, 65,| 23, 9 --> i = 4, j = 3, key = 23
    //    7, 12, 54, 65,| 65, 9 --> i = 4, j = 2, key = 23
    //    7, 12, 54, 54,| 65, 9 --> i = 4, j = 1, key = 23
    //    7, 12, 23, 54,| 65, 9 --> i = 4, j = 0, key = 23  --> 4th pass done (i = 4)

    //    7, 12, 23, 54, 65,| 9 --> i = 5, j = 4, key = 9
    //    7, 12, 23, 54, 65,| 65 --> i = 5, j = 3, key = 9
    //    7, 12, 23, 54, 54,| 65 --> i = 5, j = 2, key = 9
    //    7, 12, 23, 23, 54,| 65 --> i = 5, j = 1, key = 9
    //    7, 12, 12, 23, 54,| 65 --> i = 5, j = 0, key = 9
    //    7, 9, 12, 23, 54,| 65 --> i = 5, j = 0, key = 9  --> 5th pass done(i = 5)
    
    

    int A[] = {12,54,65,7,23,9};
    int n = 6;

    insertionSort(A,n);
    printArray(A,n);

    return 0;
}
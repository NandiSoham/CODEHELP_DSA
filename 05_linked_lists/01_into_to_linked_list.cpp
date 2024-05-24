#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
  
    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }
  
    // Parameterized Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Solution {
public:
    Node* constructLL(vector<int>& arr) {
        if (arr.empty()) return nullptr; // Check if the array is empty

        Node* head = new Node(arr[0]);
        Node* mover = head;
        
        for(int i = 1; i < arr.size(); i++) {
            Node* temp = new Node(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }
};

int main() {
    // Example array
    vector<int> arr = {1, 2, 3, 4, 5};

    Solution obj;
    Node* ans = obj.constructLL(arr);
    while (ans) {
        cout << ans->data << " ";
        ans = ans->next;
    }
    cout << "\n";

    return 0;
}

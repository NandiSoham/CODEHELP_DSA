#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    bool searchKey(int n, struct Node* head, int key) {
        Node* temp = head;
        
        while(temp){
            if(temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }
};


int main() {
    int n = 5;
    vector<int> values = {1, 21, 13, 48, 65};
    int key = 21;

    struct Node *head = new Node(values[0]);
    struct Node *tail = head;
    for (int i = 1; i < n; ++i) {
        tail->next = new Node(values[i]);
        tail = tail->next;
    }

    Solution ob;
    cout << ob.searchKey(n, head, key) << endl;

    return 0;
}

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

// Function to print the linked list starting from the given head
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* deleteHead(Node* head){
    if(!head) return head;

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main() {
    // Example array
    vector<int> arr = {12, 5, 8, 7};
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    head = deleteHead(head);
    printLL(head);
}

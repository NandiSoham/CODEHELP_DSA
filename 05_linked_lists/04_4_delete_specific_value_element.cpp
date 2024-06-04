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


Node *constructLL(vector<int> &arr)
{
    if (arr.empty())
        return NULL; // Check if the array is empty

    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Function to print the linked list starting from the given head
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* deleteElement(Node* head, int element){
    if(head == NULL) return head;

    if(head->data == element){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        if(temp->data == element){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    // Example array
    vector<int> arr = {12, 5, 8, 7, 56};
    Node * head = constructLL(arr);
    cout << "LinkedList before deleting mentioned Element : " ;
    printLL(head);
    cout << endl<< "LinkedList after deleting mentioned Element : ";
    head = deleteElement(head, 7);
    printLL(head);
}

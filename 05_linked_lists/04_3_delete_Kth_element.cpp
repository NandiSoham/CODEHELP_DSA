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

Node* deleteKthElement(Node* head, int k){
    if(head == NULL) return head;

    if(k == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int counter = 0;
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        counter++;
        if(counter == k){
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
    cout << "LinkedList before deleting Kth Node : " ;
    printLL(head);
    cout << endl<< "LinkedList after deleting Kth Node : ";
    head = deleteKthElement(head, 4);
    printLL(head);
}

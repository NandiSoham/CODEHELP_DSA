#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterized Constructor
    Node(int data)
    {
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
void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *deleteHead(Node *head)
{
    if(!head) return NULL;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main()
{
    // Example array
    vector<int> arr = {123, 46, 8, 12, 25, 8, 7};
    Node * head = constructLL(arr);
    cout << "LinkedList before deleting head : " ;
    printLL(head);
    cout << endl<< "LinkedList after deleting head : ";
    head = deleteHead(head);
    printLL(head);
}

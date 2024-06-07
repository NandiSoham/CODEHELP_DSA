#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};

// --------------------------------- Approach - 1 ----------------------------

Node *reverseListApproach1(Node *head)
{
    Node *temp = head;
    stack<int> st;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

//----------------------------------------------------------------------------

// --------------------------------- Approach - 2 ----------------------------

Node *reverseListApproach2(Node *head)
{
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

//----------------------------------------------------------------------------

// --------------------------------- Approach - 3 (Recursive Approach) ----------------------------

Node *reverseListApproach3(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newHead = reverseListApproach3(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

//----------------------------------------------------------------------------

// Function to print the linked list
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    Node *head = new Node(27);
    head->next = new Node(31);
    head->next->next = new Node(9);
    head->next->next->next = new Node(354);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // head = reverseListApproach1(head);
    // head = reverseListApproach2(head);
    head = reverseListApproach3(head);

    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}

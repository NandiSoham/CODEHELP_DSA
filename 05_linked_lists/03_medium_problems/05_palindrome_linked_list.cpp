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
        next = nullptr;
    }
};

// ------------------------------ Approach -1 ----------------------------

bool isPalindromeApproach1(Node *head)
{
    Node *currNode = head;
    vector<int> nodeArr;

    while (currNode)
    {
        nodeArr.push_back(currNode->data);
        currNode = currNode->next;
    }

    int i = 0, j = nodeArr.size() - 1;

    while (i < j)
    {
        if (nodeArr[i] != nodeArr[j])
            return false;
        i++, j--;
    }
    return true;
}

// -----------------------------------------------------------------------

// ------------------------------ Approach -2 ----------------------------

bool isPalindrome(Node* head) {
    stack<int> st;
    Node* temp = head;

    while (temp != NULL) {
        st.push(temp->data); 
        temp = temp->next;  
    }

    temp = head;
    while (temp != NULL) {
        if (temp->data != st.top()) {
            return false; 
        }

        st.pop();         
        temp = temp->next; 
    }

    return true;
}

// -----------------------------------------------------------------------

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
    Node *head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);


    cout << "Original Linked List: ";
    printLinkedList(head);

    if (isPalindromeApproach1(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}

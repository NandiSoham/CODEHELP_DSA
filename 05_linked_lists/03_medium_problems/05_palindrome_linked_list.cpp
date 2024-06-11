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

bool isPalindromeApproach2(Node *head)
{
    stack<int> st;
    Node *temp = head;

    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        if (temp->data != st.top())
        {
            return false;
        }

        st.pop();
        temp = temp->next;
    }

    return true;
}

// -----------------------------------------------------------------------

// ------------------------------ Approach -3 ----------------------------

Node *reverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *newHead = reverseList(head->next);
    Node *frontNode = head->next;
    frontNode->next = head;
    head->next = NULL;

    return newHead;
}

bool isPalindromeApproach3(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newHead = reverseList(slow->next);
    Node *firstHalfPtr = head;
    Node *secondHalfPtr = newHead;

    while (secondHalfPtr != NULL)
    {
        if (firstHalfPtr->data != secondHalfPtr->data)
        {
            reverseList(newHead);
            return false;
        }
        firstHalfPtr = firstHalfPtr->next;
        secondHalfPtr = secondHalfPtr->next;
    }
    reverseList(newHead);
    return true;
}

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
    head->next = new Node(7);
    head->next->next = new Node(2);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printLinkedList(head);

    if (isPalindromeApproach3(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}

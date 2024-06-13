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

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// ------------------------------ Approach -1 ----------------------------

Node *removeNthFromEndApproach1(Node *head, int n)
{
    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (count == n)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }

    int nodePosition = count - n;
    temp = head;

    while (temp != NULL)
    {
        nodePosition--;
        if (nodePosition == 0)
            break;
        temp = temp->next;
    }

    Node *delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
    return head;
}

// -----------------------------------------------------------------------

// ------------------------------ Approach -2 ----------------------------

Node *removeNthFromEndApproach2(Node *head, int n)
{
    Node *temp = head;
    Node *prev = head;

    for (int i = 0; i < n; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
        return head->next;

    while (temp->next != NULL)
    {
        temp = temp->next;
        prev = prev->next;
    }

    Node *delNode = prev->next;
    prev->next = prev->next->next;
    delete delNode;

    return head;
}

// -----------------------------------------------------------------------

int main()
{
    // vector<int> arr = {1, 2, 3, 4, 5};
    int N = 5;
    Node *head = new Node(4);
    head->next = new Node(23);
    head->next->next = new Node(37);
    head->next->next->next = new Node(17);
    head->next->next->next->next = new Node(55);
    head->next->next->next->next->next = new Node(6);

    cout << "Original Linked List: ";
    printLL(head);
    cout << endl;

    // head = removeNthFromEndApproach1(head, N);
    head = removeNthFromEndApproach2(head, N);

    cout << "After Deleting The Linked List: ";
    printLL(head);

    return 0;
}

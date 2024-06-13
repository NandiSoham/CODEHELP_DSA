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

int main()
{
    // vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout << "Original Linked List: ";
    printLL(head);
    cout << endl;

    head = removeNthFromEndApproach1(head, N);
    
    cout << "After Deleting The Linked List: ";
    printLL(head);

    return 0;
}

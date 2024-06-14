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

Node *deleteMiddleApproach1(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    int nodeCount = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        nodeCount++;
        temp = temp->next;
    }

    int targetNode = nodeCount / 2;
    temp = head;

    // Traverse to the node just before the middle node
    for (int i = 0; i < targetNode - 1; ++i)
    {
        temp = temp->next;
    }

    // Delete the middle node
    Node *midNode = temp->next;
    temp->next = temp->next->next;
    delete midNode;

    return head;
}

// -----------------------------------------------------------------------

// ------------------------------ Approach -2 ----------------------------

Node *deleteMiddleApproach2(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;
    Node *prevSlow = NULL;

    while (fast && fast->next)
    {
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prevSlow->next = slow->next;
    delete (slow);

    return head;
}

// -----------------------------------------------------------------------

int main()
{
    Node *head = new Node(46);
    head->next = new Node(2);
    head->next->next = new Node(13);
    head->next->next->next = new Node(56);
    head->next->next->next->next = new Node(37);
    head->next->next->next->next->next = new Node(69);
    head->next->next->next->next->next->next = new Node(18);

    cout << "Original Linked List: ";
    printLL(head);
    cout << endl;

    // head = deleteMiddleApproach1(head);
    head = deleteMiddleApproach2(head);

    cout << "After Deleting Middle Node: ";
    printLL(head);

    return 0;
}

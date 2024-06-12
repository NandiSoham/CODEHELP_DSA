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

Node *oddEvenListApproach1(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *oddTemp = head;
    Node *evenTemp = head->next;
    vector<int> arr;

    while (oddTemp != NULL && oddTemp->next != NULL)
    {
        arr.push_back(oddTemp->data);
        oddTemp = oddTemp->next->next;
    }
    if (oddTemp)
        arr.push_back(oddTemp->data);

    while (evenTemp != NULL && evenTemp->next != NULL)
    {
        arr.push_back(evenTemp->data);
        evenTemp = evenTemp->next->next;
    }
    if (evenTemp)
        arr.push_back(evenTemp->data);

    Node *temp = head;
    int idx = 0;
    while (temp != NULL)
    {
        temp->data = arr[idx];
        idx++;
        temp = temp->next;
    }

    return head;
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
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original Linked List: ";
    printLinkedList(head);

    head = oddEvenListApproach1(head);

    cout << "Reordered Linked List: ";
    printLinkedList(head);

    return 0;
}

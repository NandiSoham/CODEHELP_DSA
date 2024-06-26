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

Node *sortListApproach1(Node *head)
{
    vector<int> arr;
    Node *temp = head;

    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());
    int idx = 0;
    temp = head;

    while (temp != NULL)
    {
        temp->data = arr[idx];
        idx++;
        temp = temp->next;
    }

    return head;
}

// -----------------------------------------------------------------------

int main()
{
    Node *head = new Node(41);
    head->next = new Node(12);
    head->next->next = new Node(132);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(71);
    head->next->next->next->next->next = new Node(39);
    head->next->next->next->next->next->next = new Node(18);
    head->next->next->next->next->next->next->next = new Node(21);

    cout << "Original Linked List: ";
    printLL(head);
    cout << endl;

    head = sortListApproach1(head);

    cout << "After Sorting Linked List: ";
    printLL(head);

    return 0;
}

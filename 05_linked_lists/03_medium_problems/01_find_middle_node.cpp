
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

Node* findMiddleApproach1(Node *head)
{
    int count = 0;
    Node *temp = head;

    while (temp)
    {
        temp = temp->next;
        count++;
    }

    int midNode = (count / 2) + 1;
    temp = head;

    while (temp != NULL)
    {
        midNode = midNode - 1;
        if (midNode == 0)
            break;
        temp = temp->next;
    }
    return temp;
}

int main()
{
    // Creating a sample linked list:
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Find the middle node
    Node *middleNode = findMiddleApproach1(head);

    // Display the value of the middle node
    cout << "The middle node value is: " << middleNode->data << endl;

    return 0;
}


#include <iostream>
#include <unordered_map>

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

//-------------------------------- BRUTE FORCE APPROACH-----------------------------

Node *detectCycleBruteForce(Node *head)
{
    Node *temp = head;
    unordered_map<Node *, int> mpp;

    while (temp != NULL)
    {
        if (mpp.find(temp) != mpp.end())
        {
            return temp;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return NULL;
}

//----------------------------------------------------------------------------------

//--------------------------------- OPTIMAL APPROACH -------------------------------

Node *detectCycleOptimal(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

//----------------------------------------------------------------------------------


int main()
{
    // Create a sample linked list with a loop
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    node1->next = node2;
    Node *node3 = new Node(3);
    node2->next = node3;
    Node *node4 = new Node(4);
    node3->next = node4;
    Node *node5 = new Node(5);
    node4->next = node5;
    // Make a loop from node5 to node2
    node5->next = node3;

    // Set the head of the linked list
    Node *head = node1;

    // Node *loopStartNode = detectCycleBruteForce(head);
    Node *loopStartNode = detectCycleOptimal(head);

    if (loopStartNode)
    {
        cout << "Loop detected. Starting node of the loop is: " << loopStartNode->data << endl;
    }
    else
    {
        cout << "No loop detected in the linked list." << endl;
    }

    return 0;
}

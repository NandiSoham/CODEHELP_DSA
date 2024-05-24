#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


class Solution
{
    public:
    int getCount(struct Node* head){
    
        int count = 0;
        if(!head) return 0;
        
        Node* temp = head;
        while(temp){
            temp = temp->next;
            count++;
        }
        return count;
    
    }
};
    



int main() 
{ 
    int n = 5;
    vector<int> values = {10, 20, 30, 40, 50};

    struct Node *head = new Node(values[0]);
    struct Node *tail = head;
    for (int i = 1; i < n; ++i)
    {
        tail->next = new Node(values[i]);
        tail = tail->next;
    }
    
    Solution ob;
    cout << "Lenght of the given list: " << ob.getCount(head) << endl;

    return 0;
}

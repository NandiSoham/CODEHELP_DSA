#include <bits/stdc++.h>

using namespace std;

class ListNode {
  public:
    int val;
  ListNode * next;
  ListNode(int x) {
    val = x;
    next = NULL;
  }
};

ListNode* constructLL(vector<int>& arr) {
        if (arr.empty()) return NULL; // Check if the array is empty

        ListNode* head = new ListNode(arr[0]);
        ListNode* mover = head;
        
        for(int i = 1; i < arr.size(); i++) {
            ListNode* temp = new ListNode(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }

void PrintList(ListNode * head) // Function to print the LinkedList
{
  ListNode * curr = head;
  for (; curr != NULL; curr = curr -> next)
    cout << curr -> val << "-->";
  cout << "null" << endl;
}

ListNode * InsertatTail(int value, ListNode * head) {
    if(head == NULL){
        return new ListNode(value);
    }

    ListNode* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    ListNode* newNode = new ListNode(value);
    temp->next = newNode;
    return head;
}

int main() {
  vector<int> arr = {12, 5, 8, 7};
  ListNode * head = constructLL(arr);
  cout << "LinkedList before inserting 100 at ending : " << endl;
  PrintList(head);
  head = InsertatTail(100, head);
  cout << "LinkedList after inserting 100 at ending : " << endl;
  PrintList(head);
  return 0;
}
#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &stack, int element){
    if(stack.empty()){
        stack.push(element);
        return;
    }

    int num = stack.top();
    stack.pop();
    insertAtBottom(stack, element);
    
    stack.push(num);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()) return;
    int num = stack.top();
    stack.pop();

    reverseStack(stack);
    insertAtBottom(stack, num);
}

int main() {
    // Create a stack
    stack<int> s;
     
    // Push elements into the stack
    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);

    // Display the stack before sorting
    cout << "Stack before sorting: ";
    stack<int> tempStack = s; // Create a temporary stack for display
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    // Sort the stack
    reverseStack(s);
     
    // Print the sorted elements
    cout << "Sorted numbers are: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}

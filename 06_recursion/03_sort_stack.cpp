#include <iostream>
#include <stack>

using namespace std;

// Function to insert an element in sorted order into a stack
void sortedInsert(stack<int> &s, int topElement) {
    if(s.empty() || topElement >= s.top()) {
        s.push(topElement);
        return;
    }
    int num = s.top();
    s.pop();
    sortedInsert(s, topElement);
    s.push(num);
}

// Function to sort a stack using recursion
stack<int> sortStack(stack<int> &s) {
    if(s.empty()) return s;
    int topElement = s.top();
    s.pop();

    sortStack(s);
    sortedInsert(s, topElement);

    return s;
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
    sortStack(s);
     
    // Print the sorted elements
    cout << "Sorted numbers are: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}

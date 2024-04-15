#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(Node* p, Node* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;

        // Check if data of both nodes is equal
        bool dataEqual = (p->data == q->data);
    
        // Recursively check left and right subtrees
        bool leftSubtreeIdentical = isSameTree(p->left, q->left);
        bool rightSubtreeIdentical = isSameTree(p->right, q->right);
        
        // Return true only if data is equal and left and right subtrees are identical
        return dataEqual && leftSubtreeIdentical && rightSubtreeIdentical;
    }
};

int main() {
    // Node1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

    // Node2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);

    Solution solution;
    
    if (solution.isSameTree(root1, root2)) {
        cout << "The binary trees are identical." << endl;
    } else {
        cout << "The binary trees are not identical." << endl;
    }

    return 0;
}
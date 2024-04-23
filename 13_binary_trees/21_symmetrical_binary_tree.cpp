                            
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


class Solution {
public:

    bool checkSymmetry(Node* left, Node* right){
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;
        if(left->data != right->data) return false;
        return(checkSymmetry(left->left, right->right) && checkSymmetry(left->right, right->left));
    }

    bool isSymmetric(Node* root) {
        if(root == NULL) return true;
        return checkSymmetry(root->left, root->right);
    }
};
 
 


// Function to print the Inorder
// Traversal of the Binary Tree
void printInorder(Node* root){
    if(!root){
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}


int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);

    Solution solution;
    
    cout << "Binary Tree (Inorder): ";
    printInorder(root);
    cout << endl;

    bool res;
    res = solution.isSymmetric(root);
    
    if(res){
        cout << "This Tree is Symmetrical" << endl;
    }
    else{
        cout << "This Tree is NOT Symmetrical" << endl;
    }

    return 0;
}
                            
                        
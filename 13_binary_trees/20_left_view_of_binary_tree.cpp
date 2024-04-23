#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    void solve(Node* root, int level, vector<int> &ans){
        if(root == NULL) return;
        if(ans.size() == level) ans.push_back(root->data);
        solve(root->right, level + 1, ans);
        solve(root->left, level + 1, ans);
    }

    vector<int> rightSideView(Node* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};


int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    // Get the Right View traversal
    vector<int> rightView = solution.rightSideView(root);

    // Print the result for Right View
    cout << "Right View Traversal: ";
    for(auto node: rightView){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

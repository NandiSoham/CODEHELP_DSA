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
    bool isLeaf(Node* root) {
        if (root->left == NULL && root->right == NULL)
            return true;
        return false;
    }

    void addLeftBoundary(Node* root, vector<int> &ans) {
        Node* curNode = root->left;
        while (curNode) {
            if (!isLeaf(curNode))
                ans.push_back(curNode->data);

            if (curNode->left)
                curNode = curNode->left;
            else
                curNode = curNode->right;
        }
    }

    void addRightBoundary(Node* root, vector<int> &ans) {
        Node* curNode = root->right;
        vector<int> temp;
        while (curNode) {
            if (!isLeaf(curNode))
                temp.push_back(curNode->data);

            if (curNode->right)
                curNode = curNode->right;
            else
                curNode = curNode->left;
        }

        for (int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
    }

    void addLeaves(Node* root, vector<int> &ans) {
        if (isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }

        if (root->left)
            addLeaves(root->left, ans);
        if (root->right)
            addLeaves(root->right, ans);
    }

    vector<int> traverseBoundary(Node* root) {
        vector<int> ans;
        if (!root)
            return ans;
        if (!isLeaf(root))
            ans.push_back(root->data);

        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);

        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    vector<int> result = solution.traverseBoundary(root);

    cout << "Boundary Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

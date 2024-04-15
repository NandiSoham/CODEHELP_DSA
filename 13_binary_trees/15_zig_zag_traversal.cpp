#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<Node*> nodeQueue;
        nodeQueue.push(root);
        bool leftToRight = true;

        while(!nodeQueue.empty()){
            int curSize = nodeQueue.size();
            vector<int> row(curSize);

            for(int i  = 0; i < curSize; i++){
                Node* node = nodeQueue.front();
                nodeQueue.pop();

                int index = leftToRight ? i : (curSize-1-i);
                row[index] = node->data;

                if(node->left != NULL) nodeQueue.push(node->left);
                if(node->right != NULL) nodeQueue.push(node->right);
            }

            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};

void printResult(const vector<vector<int>>& result) {
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    vector<vector<int>> result = solution.zigzagLevelOrder(root);
    printResult(result);

    return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(Node* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> nodesQue;
        nodesQue.push({root, {0, 0}});

        while(!nodesQue.empty()){
            auto iterator = nodesQue.front();
            nodesQue.pop();
            Node* tempNode = iterator.first;
            int x = iterator.second.first;
            int y = iterator.second.second;
            nodes[x][y].insert(tempNode-> data);

            if(tempNode->left){
                nodesQue.push({tempNode->left, {x - 1, y + 1}});
            }
            if(tempNode->right){
                nodesQue.push({tempNode->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;
        for(auto it : nodes){
            vector<int> col;
            for(auto q : it.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
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

    vector<vector<int>> result = solution.verticalTraversal(root);

    cout << "Vertical Traversal: \n";
    for (auto vec : result) {
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
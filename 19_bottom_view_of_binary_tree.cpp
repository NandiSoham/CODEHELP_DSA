#include <iostream>
#include <vector>
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

class Solution{
public:
    vector<int> bottomView(Node* root){
        // Vector to store the result
        vector<int> ans;
        
        // Check if the tree is empty
        if(root == NULL){
            return ans;
        }
        
        // Map to store the top view nodes
        // based on their vertical positions
        map<int, int> nodesMap;
        
        // Queue for BFS traversal, each element
        // is a pair containing node 
        // and its vertical position
        queue<pair <Node*, int>> nodesQue;
        
        // Push the root node with its vertical
        // position (0) into the queue
        nodesQue.push({root, 0});
        
        // BFS traversal
        while(!nodesQue.empty()){
            // Retrieve the node and its vertical
            // position from the front of the queue
            auto it = nodesQue.front();
            nodesQue.pop();
            Node* curNode = it.first;
            int line = it.second;
            nodesMap[line] = curNode->data;

            
            // Process left child
            if(curNode->left != NULL){
                // Push the left child with a decreased
                // vertical position into the queue
                nodesQue.push({curNode->left, line - 1});
            }
            
            // Process right child
            if(curNode->right != NULL){
                // Push the right child with an increased
                // vertical position into the queue
                nodesQue.push({curNode->right, line + 1});
            }
        }
        
        // Transfer values from the
        // map to the result vector
        for(auto it : nodesMap){
            ans.push_back(it.second);
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

    // Get the top view traversal
    vector<int> bottomView =
                    solution.bottomView(root);

    // Print the result
    cout << "Bottom View Traversal: "<< endl;
    for(auto node: bottomView){
        cout << node << " ";
    }

    return 0;
}
                            
                        
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*>q;

        if(root == NULL) return ans;
        q.push(root);

        while(!q.empty()){
            int queSize = q.size();
            vector<int> vtr;
            for(int  i= 0; i < queSize; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                vtr.push_back(temp->val);
            }
            ans.push_back(vtr);
        }
        return ans;
    }
};

void printVector(const vector<int>& vec) {
    
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}


int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution; 
    vector<vector<int>> result = solution.levelOrder(root); 

    cout << "Level Order Traversal of Tree: "<< endl;

    for (const vector<int>& level : result) {
        printVector(level);
    }

    return 0;
}
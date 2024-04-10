#include <iostream>
#include <vector>
#include<stack>
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

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;

    if (root == NULL)
        return ans;
    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();
        ans.push_back(root->val);

        if (root->right != NULL)
            st.push(root->right);

        if (root->left != NULL)
            st.push(root->left);
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
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

class Solution
{
public:
    int maxSumDown(Node *node, int &maxi)
    {
        if (node == NULL)
            return 0;

        int leftPartMaxSum = max(0, maxSumDown(node->left, maxi));
        int rightPartMaxSum = max(0, maxSumDown(node->right, maxi));

        maxi = max(maxi, node->data + leftPartMaxSum + rightPartMaxSum);

        return node->data + max(leftPartMaxSum, rightPartMaxSum);
    }

    int maxPathSum(Node *root)
    {
        int maxi = INT_MIN;
        maxSumDown(root, maxi);
        return maxi;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    Solution solution;

    int maxPathSum = solution.maxPathSum(root);
    cout << "Maximum Path Sum: " << maxPathSum << endl;

    return 0;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        stack<TreeNode *> nodeStack;

        while (root != nullptr) {
            if (root->right != nullptr)
                nodeStack.push(root->right);

            if (root->left != nullptr)
                root->right = root->left;
            else if (!nodeStack.empty()) {
                root->right = nodeStack.top();
                nodeStack.pop();
            }
            root->left = nullptr;
            root = root->right;
        }
    }
};

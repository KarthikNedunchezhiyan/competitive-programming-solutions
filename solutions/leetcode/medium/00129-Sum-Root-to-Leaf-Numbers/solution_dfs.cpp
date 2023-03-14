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
    int sumNumbers(TreeNode* root, int buffer) {
        if (!root) return 0;

        buffer = (buffer * 10) + root->val;
        if (!root->left && !root->right) return buffer;

        return sumNumbers(root->left, buffer) + sumNumbers(root->right, buffer);
    }
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
};

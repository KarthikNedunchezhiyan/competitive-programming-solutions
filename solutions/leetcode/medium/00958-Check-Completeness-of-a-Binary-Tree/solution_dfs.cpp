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
    int count(TreeNode *root) {
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }

    int isBalanced(TreeNode *root, int index, int size) {
        if (!root) return true;
        if (index >= size) return false;

        return isBalanced(root->left, index * 2 + 1, size) &&
               isBalanced(root->right, index * 2 + 2, size);
    }

public:
    bool isCompleteTree(TreeNode *root) {
        return isBalanced(root, 0, count(root));
    }
};

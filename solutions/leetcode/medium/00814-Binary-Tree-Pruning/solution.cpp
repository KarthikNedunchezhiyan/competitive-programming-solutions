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
private:
    bool prune(TreeNode *root) {
        if (root == nullptr)
            return false;

        bool left = prune(root->left);
        if (!left) root->left = nullptr;

        bool right = prune(root->right);
        if (!right) root->right = nullptr;

        return left || right || root->val == 1;
    }

public:
    TreeNode *pruneTree(TreeNode *root) {
        return prune(root) ? root : nullptr;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *result = nullptr;

    bool traverse(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr)
            return false;

        int left = traverse(root->left, p, q);
        int right = traverse(root->right, p, q);
        int mid = root == p || root == q;

        if (left + right + mid >= 2)
            this->result = root;

        return left + right + mid;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        traverse(root, p, q);

        return this->result;
    }
};

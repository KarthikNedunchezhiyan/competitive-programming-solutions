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
    TreeNode *_flatten(TreeNode *root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return root;

        TreeNode *l_leaf = _flatten(root->left);
        TreeNode *r_leaf = _flatten(root->right);

        if (l_leaf != nullptr && root->right != nullptr)
            l_leaf->right = root->right;

        if (root->left != nullptr)
            root->right = root->left;

        root->left = nullptr;
        return r_leaf != nullptr ? r_leaf : l_leaf;
    }

public:
    void flatten(TreeNode *root) {
        _flatten(root);
    }
};

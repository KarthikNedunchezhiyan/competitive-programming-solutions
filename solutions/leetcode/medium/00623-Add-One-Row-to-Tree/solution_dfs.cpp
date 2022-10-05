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
    TreeNode *add(TreeNode *root, int val, int depth) {
        if (root == nullptr) return root;

        if (depth == 1) {
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);
        } else {
            add(root->left, val, depth - 1);
            add(root->right, val, depth - 1);
        }

        return root;
    }

public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth) {
        return depth == 1 ? new TreeNode(val, root, nullptr) : add(root, val, depth - 1);
    }
};

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
    int countGoodNodes(TreeNode *root, int maxSoFar) {
        if (root == nullptr)
            return 0;
        
        return countGoodNodes(root->left, max(maxSoFar, root->val)) +
               countGoodNodes(root->right, max(maxSoFar, root->val)) +
               (root->val >= maxSoFar ? 1 : 0);
    }

public:
    int goodNodes(TreeNode *root) {
        return countGoodNodes(root, -10001);
    }
};

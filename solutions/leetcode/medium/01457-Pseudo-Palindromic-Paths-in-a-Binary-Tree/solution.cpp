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
    int buffer;

public:
    int pseudoPalindromicPaths(TreeNode *root) {
        if (root == nullptr) return 0;

        buffer ^= 1 << root->val;
        int result = root->right == nullptr && root->left == nullptr ?
                     buffer == 0 || __builtin_popcount(buffer) == 1 :
                     pseudoPalindromicPaths(root->left) + pseudoPalindromicPaths(root->right);
        buffer ^= 1 << root->val;
        return result;
    }
};

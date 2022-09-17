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
    int f(TreeNode *root, int prev, int subsequence_len) {
        if (root == nullptr) return subsequence_len;

        int next_subsequence_len = ((prev + 1) == root->val) ? subsequence_len + 1 : 1;

        return max(subsequence_len, max(f(root->left, root->val, next_subsequence_len),
                                        f(root->right, root->val, next_subsequence_len)));
    }

public:
    int longestConsecutive(TreeNode *root) {
        return f(root, INT_MIN, 1);
    }
};

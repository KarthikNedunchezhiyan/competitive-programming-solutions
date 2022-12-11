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
    int max_path_sum = INT_MIN;

    int traverse(TreeNode *root) {
        if (!root) return 0;

        int left_max_sum = traverse(root->left);
        int right_max_sum = traverse(root->right);
        
        max_path_sum = max(max_path_sum, root->val + max(0, left_max_sum) + max(0, right_max_sum));

        return root->val + max(0, max(left_max_sum, right_max_sum));
    }

public:
    int maxPathSum(TreeNode *root) {
        traverse(root);
        return max_path_sum;
    }
};

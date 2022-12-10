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
    int search(TreeNode *root, int ancestral_max, int ancestral_min) {
        if (!root) return INT_MIN;

        int result = max(abs(ancestral_min - root->val), abs(ancestral_max - root->val));
        ancestral_max = max(ancestral_max, root->val), ancestral_min = min(ancestral_min, root->val);
        result = max(result, search(root->left, ancestral_max, ancestral_min));
        return max(result, search(root->right, ancestral_max, ancestral_min));
    }

public:
    int maxAncestorDiff(TreeNode *root) {
        return search(root, root->val, root->val);
    }
};

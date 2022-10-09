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
public:
    bool findTarget(TreeNode *root, int k) {
        unordered_map<int, int> node_vals;

        function<bool(TreeNode *)> dfs = [&](TreeNode *root) {
            if (root == nullptr) return false;

            if (node_vals.count(k - root->val)) return true;
            ++node_vals[root->val];
            return dfs(root->left) || dfs(root->right);
        };

        return dfs(root);
    }
};

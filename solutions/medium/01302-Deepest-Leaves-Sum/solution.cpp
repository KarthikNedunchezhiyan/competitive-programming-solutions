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
    int deepLevel = 0;
    int deepLevelLeavesSum = 0;

    void dfs(TreeNode *root, int level) {
        if (root == nullptr)
            return;

        if (level > deepLevel) {
            deepLevel = level;
            deepLevelLeavesSum = 0;
        }

        if (level == deepLevel)
            deepLevelLeavesSum += root->val;

        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }

public:
    int deepestLeavesSum(TreeNode *root) {
        dfs(root, 0);
        return deepLevelLeavesSum;
    }
};

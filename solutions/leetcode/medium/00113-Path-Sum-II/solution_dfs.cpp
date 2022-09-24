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
    int buffer[5001], buffer_size = 0;

    void dfs(TreeNode *root, int targetSum, vector<vector<int>> &result) {
        if (!root) return;

        buffer[buffer_size++] = root->val;

        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == root->val) result.push_back(vector(begin(buffer), begin(buffer) + buffer_size));
        } else {
            dfs(root->left, targetSum - root->val, result);
            dfs(root->right, targetSum - root->val, result);
        }
        --buffer_size;
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<vector<int>> result;
        dfs(root, targetSum, result);
        return result;
    }
};

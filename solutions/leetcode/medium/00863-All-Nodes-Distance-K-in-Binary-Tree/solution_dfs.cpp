/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void collectAtDepth(TreeNode *root, int current_depth, int target_depth, vector<int> &buffer) {
        if (root == nullptr || current_depth > target_depth) return;

        if (current_depth == target_depth) return buffer.push_back(root->val);

        collectAtDepth(root->left, current_depth + 1, target_depth, buffer);
        collectAtDepth(root->right, current_depth + 1, target_depth, buffer);
    }

    int f(TreeNode *root, TreeNode *target, int current_depth, int k, vector<int> &buffer) {
        if (root == nullptr) return -1;
        if (root == target) return 1;

        int depth = f(root->left, target, current_depth + 1, k, buffer);

        if (depth != -1)
            collectAtDepth(root->right, 1, k - depth, buffer);
        else {
            depth = f(root->right, target, current_depth + 1, k, buffer);
            if (depth != -1)
                collectAtDepth(root->left, 1, k - depth, buffer);
        }

        if (!(depth - k)) buffer.push_back(root->val);

        return depth == -1 ? depth : depth + 1;
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        if (!k) return {target->val};

        vector<int> result;
        f(root, target, 0, k, result);
        collectAtDepth(target, 0, k, result);

        return result;
    }
};

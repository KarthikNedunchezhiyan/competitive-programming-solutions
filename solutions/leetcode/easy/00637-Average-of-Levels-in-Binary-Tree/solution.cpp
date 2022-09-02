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
    map<int, pair<double, int>> level;

    void recordLevelValues(TreeNode *root, int depth) {
        if (root == nullptr) return;

        auto entry = level.find(depth);
        if (entry == level.end())
            level[depth] = {root->val, 1};
        else {
            entry->second.first += root->val;
            entry->second.second++;
        }

        recordLevelValues(root->left, depth + 1);
        recordLevelValues(root->right, depth + 1);
    }

public:
    vector<double> averageOfLevels(TreeNode *root) {
        recordLevelValues(root, 1);
        vector<double> result;
        result.reserve(level.size());
        for (auto l: level)
            result.push_back(l.second.first / l.second.second);

        return result;
    }
};

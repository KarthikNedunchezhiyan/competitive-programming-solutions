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
    map<int, map<int, vector<int>>> vertical_order;

    void record(TreeNode *root, int row, int column) {
        if (root == nullptr)
            return;

        auto col_pointer = vertical_order.find(column);
        if (col_pointer == vertical_order.end())
            vertical_order[column] = {{row, {root->val}}};
        else {
            auto row_pointer = col_pointer->second.find(row);
            if (row_pointer == col_pointer->second.end())
                col_pointer->second[row] = {root->val};
            else
                row_pointer->second.push_back(root->val);
        }

        record(root->left, row + 1, column - 1);
        record(root->right, row + 1, column + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        record(root, 0, 0);

        vector<vector<int>> result;
        result.reserve(vertical_order.size());

        for (auto col: vertical_order) {
            vector<int> res;
            for (auto row: col.second) {
                sort(row.second.begin(), row.second.end());
                res.reserve(res.size() + row.second.size());
                res.insert(res.end(), row.second.begin(), row.second.end());
            }
            result.push_back(res);
        }

        return result;
    }
};

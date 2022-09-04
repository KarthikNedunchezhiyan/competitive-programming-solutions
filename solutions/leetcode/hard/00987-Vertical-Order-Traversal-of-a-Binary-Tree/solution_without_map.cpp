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
struct Entry {
public:
    int first, second, third;

    Entry(int first, int second, int third) {
        this->first = first;
        this->second = second;
        this->third = third;
    }
};

class Solution {
private:
    vector<Entry> vertical_order;

    void record(TreeNode *root, int row, int column) {
        if (root == nullptr)
            return;

        vertical_order.emplace_back(column, row, root->val);

        record(root->left, row + 1, column - 1);
        record(root->right, row + 1, column + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        record(root, 0, 0);
        vector<vector<int>> result;

        sort(vertical_order.begin(), vertical_order.end(), [](Entry &entry1, Entry &entry2) {
            return entry1.first != entry2.first ? entry1.first < entry2.first :
                   entry1.second != entry2.second ?
                   entry1.second < entry2.second : entry1.third < entry2.third;
        });

        for (int i = 0; i < vertical_order.size(); i++) {
            if (i == 0 || vertical_order[i].first != vertical_order[i - 1].first)
                result.push_back({});
            result.back().push_back(vertical_order[i].third);
        }

        return result;
    }
};

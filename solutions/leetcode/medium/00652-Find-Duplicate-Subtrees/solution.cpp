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
std::hash<std::string> hasher;

class Solution {
    string construct(TreeNode *root, unordered_map<size_t, vector<TreeNode *>> &lookup) {
        if (!root) return "(n)";

        string fingerprint =
                "(" + construct(root->left, lookup) + to_string(root->val) + construct(root->right, lookup) + ")";

        size_t hash = hasher(fingerprint);

        auto it = lookup.find(hash);
        if (it != lookup.end()) {
            if (it->second.size() == 1) it->second.push_back(root);
        } else {
            lookup[hash] = {root};
        }

        return fingerprint;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        unordered_map<size_t, vector<TreeNode *>> lookup;
        construct(root, lookup);

        vector<TreeNode *> result;

        for (auto &entry: lookup) {
            if (entry.second.size() > 1) result.push_back(entry.second.front());
        }
        return result;
    }
};

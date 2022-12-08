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
    void getLeafSequence(TreeNode *cursor, vector<int> &buffer) {
        if (!cursor) return;
        if (!cursor->left && !cursor->right) return buffer.push_back(cursor->val);
        getLeafSequence(cursor->left, buffer);
        getLeafSequence(cursor->right, buffer);
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> root1_leaf_sequence, root2_leaf_sequence;
        getLeafSequence(root1, root1_leaf_sequence);
        getLeafSequence(root2, root2_leaf_sequence);

        return root1_leaf_sequence == root2_leaf_sequence;
    }
};

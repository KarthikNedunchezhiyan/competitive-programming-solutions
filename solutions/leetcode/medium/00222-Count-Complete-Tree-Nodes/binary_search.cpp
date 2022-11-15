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
    bool nodeExist(int left, int right, int target, int m_depth, TreeNode *root) {
        int c_depth = 0;
        while (root && (c_depth < m_depth)) {
            int pivot = left + (right - left) / 2;
            if (target <= pivot) {
                right = pivot;
                root = root->left;
            } else {
                left = pivot + 1;
                root = root->right;
            }
            ++c_depth;
        }

        return root;
    }

    int search(int left, int right, int m_depth, TreeNode *root) {
        int l = left, r = right;
        while ((r - l) > 1) {
            int pivot = l + (r - l) / 2;
            if (nodeExist(left, right, pivot, m_depth, root)) l = pivot;
            else r = pivot - 1;
        }

        return nodeExist(left, right, r, m_depth, root) ? r : l;
    }

    int findHeight(TreeNode *root, bool dir_left) {
        int height = 0;
        while (root) {
            ++height;
            root = dir_left ? root->left : root->right;
        }
        return height - 1;
    }

public:
    int countNodes(TreeNode *root) {
        if (!root) return 0;

        int height = findHeight(root, true);

        if (height == findHeight(root, false)) return pow(2, height + 1) - 1;

        int left = 1, right = pow(2, height);
        int last_leaf_id = search(left, right, height, root);

        return (2 * right) - (right - last_leaf_id) - 1;
    }
};

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
    double target;

    int search(TreeNode *cursor, int nodeBest, double absBest) {
        if (cursor == nullptr)
            return nodeBest;

        double currAbs = abs(cursor->val - target);
        if (currAbs < absBest) {
            absBest = currAbs;
            nodeBest = cursor->val;
        }

        return search(target >= cursor->val ? cursor->right : cursor->left, nodeBest, absBest);
    }

public:
    int closestValue(TreeNode *root, double target) {
        this->target = target;
        return search(root, 0, INT_MAX);
    }
};

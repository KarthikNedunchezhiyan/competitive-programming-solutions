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
    long root_branch_sum, max_product = 0;

    long max(long a, long b) {
        return a > b ? a : b;
    }

    int populateBranchSum(TreeNode *root) {
        if (!root) return 0;
        return root->val + populateBranchSum(root->left) + populateBranchSum(root->right);
    }

    long getBranchSum(TreeNode *root) {
        if (!root) return 0;
        long left_child_bsum = getBranchSum(root->left), right_child_bsum = getBranchSum(root->right);
        long ancestral_bsum = root_branch_sum - left_child_bsum - right_child_bsum;
//      max_product = max(max_product, max((ancestral_bsum + left_child_bsum) * right_child_bsum,
//                                           (ancestral_bsum + right_child_bsum) * left_child_bsum));
        // simplified form of the above equation (both are same).
        max_product = max(max_product, (left_child_bsum * right_child_bsum) +
                                       (ancestral_bsum * max(left_child_bsum, right_child_bsum)));
        return root->val + left_child_bsum + right_child_bsum;
    }

public:
    int maxProduct(TreeNode *root) {
        root_branch_sum = populateBranchSum(root);
        getBranchSum(root);
        return max_product % 1000000007;
    }
};

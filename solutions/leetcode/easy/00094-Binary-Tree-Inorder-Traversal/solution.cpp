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
    vector<int> result;
    void populate(TreeNode* root) {
        if(root == nullptr)
            return;

        populate(root->left);
        result.push_back(root->val);
        populate(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        populate(root);
        return result;
    }
};

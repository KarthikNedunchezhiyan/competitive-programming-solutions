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
public:
    bool isCompleteTree(TreeNode *root) {
        if (!root) return true;

        queue<TreeNode *> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            if (!bfs.front()) {
                while (!bfs.empty() && !bfs.front()) bfs.pop();
                break;
            }
            bfs.push(bfs.front()->left);
            bfs.push(bfs.front()->right);
            bfs.pop();
        }

        return bfs.empty();
    }
};

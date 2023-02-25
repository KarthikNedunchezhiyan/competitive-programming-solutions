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
    TreeNode *construct(string &s, int &cursor) {
        if (cursor >= s.length()) return nullptr;

        int start = cursor;
        if (s[cursor] == '-') ++cursor;

        while (isdigit(s[cursor])) ++cursor;

        TreeNode *head = new TreeNode(stoi(s.substr(start, cursor - start)));

        if (s[cursor] == '(') {
            head->left = construct(s, ++cursor);
            ++cursor;
        }
        if (s[cursor] == '(') {
            head->right = construct(s, ++cursor);
            ++cursor;
        }

        return head;
    }

public:
    TreeNode *str2tree(string s) {
        int cursor = 0;
        return construct(s, cursor);
    }
};

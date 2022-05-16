/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    vector<Node *> rightTracker;

    void f(Node *root, int level) {
        if (root == nullptr)
            return;

        if (rightTracker.size() > level) {
            root->next = rightTracker[level];
            rightTracker[level] = root;
        } else
            rightTracker.push_back(root);

        f(root->right, level + 1);
        f(root->left, level + 1);
    }

public:
    Node *connect(Node *root) {
        f(root, 0);
        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        if (root == nullptr)
            return {};

        vector<vector<int>> result;
        queue<Node *> bfsQ;
        bfsQ.push(root);

        while (!bfsQ.empty()) {
            result.push_back({});

            int queueSize = bfsQ.size();
            while (queueSize-- > 0) {
                Node *frontNode = bfsQ.front();
                bfsQ.pop();
                result.back().push_back(frontNode->val);

                for (Node *child: frontNode->children)
                    if (child != nullptr) bfsQ.push(child);
            }
        }

        return result;
    }
};

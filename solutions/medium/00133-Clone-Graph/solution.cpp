/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    map<int, Node *> referenceMap;
    
public:
    Node *cloneGraph(Node *node) {
        if (node == nullptr)
            return node;

        if (referenceMap.find(node->val) != referenceMap.end())
            return referenceMap[node->val];

        referenceMap[node->val] = new Node(node->val);

        for (Node *neighbour: node->neighbors)
            referenceMap[node->val]->neighbors.push_back(cloneGraph(neighbour));

        return referenceMap[node->val];
    }
};

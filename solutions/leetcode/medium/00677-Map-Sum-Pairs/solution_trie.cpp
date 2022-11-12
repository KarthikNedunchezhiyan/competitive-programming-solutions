struct Node {
    int prefix_sum = 0, val = 0;
    Node *children[26] = {};

    Node() {}
};

class MapSum {
    Node *head;

    int _insert(int depth, string &word, int val, Node *current) {
        if (depth == word.size()) {
            int diff = val - current->val;
            current->val = val;
            return diff;
        }

        Node *child = current->children[word[depth] - 'a'];
        if (!child) child = current->children[word[depth] - 'a'] = new Node();

        int diff = _insert(depth + 1, word, val, child);
        child->prefix_sum += diff;
        return diff;
    }

public:
    MapSum() {
        head = new Node();
    }

    void insert(string key, int val) {
        _insert(0, key, val, head);
    }

    int sum(string prefix) {
        int depth = 0;
        Node *cursor = head;
        while (depth < prefix.size()) {
            if (!cursor->children[prefix[depth] - 'a']) return 0;
            cursor = cursor->children[prefix[depth++] - 'a'];
        }

        return cursor->prefix_sum;
    }
};

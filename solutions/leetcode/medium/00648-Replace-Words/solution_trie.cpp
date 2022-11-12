struct Node {
    int root_index = -1;
    Node *children[26] = {};
};

class PrefixTree {
    Node *head;
public:
    PrefixTree() {
        head = new Node();
    }

    void insert(string &word, int index) {
        Node *cursor = head;
        int w_i = 0;
        while (w_i < word.size()) {
            if (cursor->root_index != -1) return;
            if (!cursor->children[word[w_i] - 'a']) cursor->children[word[w_i] - 'a'] = new Node();
            cursor = cursor->children[word[w_i++] - 'a'];
        }

        cursor->root_index = index;
    }

    int search(int i, string &sentence) {
        Node *cursor = head;

        while (i < sentence.size() && sentence[i] != ' ') {
            if (cursor->root_index != -1) return cursor->root_index;
            if (!cursor->children[sentence[i] - 'a']) return -1;
            cursor = cursor->children[sentence[i++] - 'a'];
        }

        return -1;
    }
};

class Solution {
public:
    string replaceWords(vector<string> &dictionary, string sentence) {
        PrefixTree *tree = new PrefixTree();
        for (int i = 0; i < dictionary.size(); ++i) tree->insert(dictionary[i], i);

        string result;
        bool no_root = false;
        const int N = sentence.length();
        for (int i = -1; i < N; ++i) {
            if (i == -1 || sentence[i] == ' ') {
                int w_i = tree->search(i + 1, sentence);
                if (!result.empty()) result.push_back(' ');
                if (w_i != -1) {
                    no_root = false;
                    result += dictionary[w_i];
                } else no_root = true;
            } else if (no_root) result.push_back(sentence[i]);
        }

        return result;
    }
};

struct Node {
    bool end = false;
    Node *children[26] = {};
};

class WordDictionary {
    Node *head = new Node();
    int longest_word = INT_MIN;

    bool _search(string &word, int w_i, Node *cursor) {
        if (w_i == word.size()) return cursor->end;

        if (word[w_i] == '.') {
            for (auto &child: cursor->children)
                if (child && _search(word, w_i + 1, child)) return true;
            return false;
        }

        return cursor->children[word[w_i] - 'a'] && _search(word, w_i + 1, cursor->children[word[w_i] - 'a']);
    }

public:
    WordDictionary() {}

    void addWord(string word) {
        longest_word = max(longest_word, (int) word.length());
        Node *cursor = head;
        int w_i = 0;

        while (w_i < word.size()) {
            if (!cursor->children[word[w_i] - 'a']) cursor->children[word[w_i] - 'a'] = new Node();
            cursor = cursor->children[word[w_i++] - 'a'];
        }
        cursor->end = true;
    }

    bool search(string word) {
        return word.length() <= longest_word && _search(word, 0, head);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

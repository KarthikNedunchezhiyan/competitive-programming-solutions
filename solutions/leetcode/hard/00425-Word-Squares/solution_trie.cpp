struct Node {
    int index = -1;
    Node *children[26] = {};
};

class PrefixTree {
    Node *head = new Node();

    void getAllIndexes(Node *cursor, vector<int> &buffer) {
        for (Node *child: cursor->children) if (child) getAllIndexes(child, buffer);
        if (cursor->index != -1) buffer.push_back(cursor->index);
    }

public:
    void insert(string &word, int index) {
        int w_i = 0;
        Node *cursor = head;

        while (w_i < word.size()) {
            if (!cursor->children[word[w_i] - 'a']) cursor->children[word[w_i] - 'a'] = new Node();
            cursor = cursor->children[word[w_i++] - 'a'];
        }
        cursor->index = index;
    }

    vector<int> prefixMatch(string word) {
        int w_i = 0;
        Node *cursor = head;

        while (w_i < word.size()) {
            if (!cursor->children[word[w_i] - 'a']) return {};
            cursor = cursor->children[word[w_i++] - 'a'];
        }

        vector<int> buffer;
        getAllIndexes(cursor, buffer);
        return buffer;
    }
};

class Solution {
    PrefixTree *tree = new PrefixTree();

    string getPrefix(vector<string_view> &buffer) {
        string prefix;
        int index = buffer.size();
        for (int i = 0; i < buffer.size(); ++i) prefix += buffer[i][index];
        return prefix;
    }

    void findAllWordSquares(vector<string_view> &buffer, vector<string> &words, vector<vector<string_view>> &squares) {
        if (buffer.size() == buffer[0].size()) {
            squares.push_back(buffer);
            return;
        }

        vector<int> matching_indexes = tree->prefixMatch(getPrefix(buffer));
        for (int index: matching_indexes) {
            buffer.push_back(words[index]);
            findAllWordSquares(buffer, words, squares);
            buffer.pop_back();
        }
    }

public:
    vector<vector<string>> wordSquares(vector<string> &words) {
        for (int i = 0; i < words.size(); ++i) tree->insert(words[i], i);
        vector<vector<string>> result;
        vector<string_view> buffer;

        for (string &word: words) {
            vector<vector<string_view>> squares;
            buffer.push_back(word);
            findAllWordSquares(buffer, words, squares);
            buffer.pop_back();

            for (vector<string_view> &square: squares) {
                result.emplace_back();
                for (string_view &word: square) result.back().emplace_back(word);
            }
        }

        return result;
    }
};

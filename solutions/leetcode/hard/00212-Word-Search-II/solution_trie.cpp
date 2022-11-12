struct Node {
    int index = -1;
    Node *children[26] = {};

    Node() {}
};

class PrefixTree {
public:
    Node *head = new Node();

    PrefixTree() {}

    void insert(string &word, int index) {
        Node *cursor = head;
        int word_i = 0;
        while (word_i < word.size()) {
            if (!cursor->children[word[word_i] - 'a'])
                cursor->children[word[word_i] - 'a'] = new Node();
            cursor = cursor->children[word[word_i] - 'a'];
            ++word_i;
        }
        cursor->index = index;
    }
};

class Solution {
    vector<int> buffer;

    void search(int i, int j, vector<vector<char>> &board, Node *cursor) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '.' ||
            !cursor->children[board[i][j] - 'a'])
            return;

        cursor = cursor->children[board[i][j] - 'a'];
        if (cursor->index != -1) {
            buffer.push_back(cursor->index);
            cursor->index = -1;
        }

        char temp = board[i][j];
        board[i][j] = '.';
        search(i + 1, j, board, cursor);
        search(i, j + 1, board, cursor);
        search(i - 1, j, board, cursor);
        search(i, j - 1, board, cursor);

        board[i][j] = temp;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        PrefixTree *tree = new PrefixTree();
        for (int i = 0; i < words.size(); ++i) tree->insert(words[i], i);

        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                search(i, j, board, tree->head);

        vector<string> result;
        for (int index: buffer) result.push_back(words[index]);

        return result;
    }
};

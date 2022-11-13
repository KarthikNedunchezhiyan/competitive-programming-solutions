struct Node {
    vector<int> s_i_list;
    // 26 english lower case chars + 1 space
    Node *children[27] = {};
};

class PrefixTree {
    Node *head = new Node();

    int cToi(char &c) {
        return c == ' ' ? 26 : c - 'a';
    }

public:
    void insert(string &word, int index) {
        Node *cursor = head;
        int w_i = 0;

        while (w_i < word.length()) {
            if (!cursor->children[cToi(word[w_i])]) cursor->children[cToi(word[w_i])] = new Node();
            cursor = cursor->children[cToi(word[w_i++])];
            cursor->s_i_list.push_back(index);
        }
    }

    vector<int> matches(string &word) {
        vector<int> result;

        Node *cursor = head;
        int w_i = 0;

        while (w_i < word.length()) {
            if (!cursor->children[cToi(word[w_i])]) return {};
            cursor = cursor->children[cToi(word[w_i++])];
        }

        return cursor->s_i_list;
    }
};

class AutocompleteSystem {
    unordered_map<string, int> s_i_lookup;
    vector<string> sentences;
    vector<int> times;
    string buffer;
    PrefixTree *tree = new PrefixTree();
public:
    AutocompleteSystem(vector<string> &sentences, vector<int> &times) {
        for (int i = 0; i < sentences.size(); ++i) {
            s_i_lookup[sentences[i]] = i;
            tree->insert(sentences[i], i);
        }
        this->sentences = sentences;
        this->times = times;
    }

    vector<string> input(char c) {
        if (c == '#') {
            if (s_i_lookup.count(buffer)) ++times[s_i_lookup[buffer]];
            else {
                sentences.push_back(buffer);
                times.push_back(1);
                s_i_lookup[buffer] = sentences.size() - 1;
                tree->insert(buffer, sentences.size() - 1);
            }
            buffer.clear();
            return {};
        }

        buffer.push_back(c);
        vector<int> s_i_list = tree->matches(buffer);

        sort(s_i_list.begin(), s_i_list.end(), [&](auto a, auto b) {
            if (times[a] != times[b]) return times[a] > times[b];
            return sentences[a] < sentences[b];
        });

        vector<string> result;
        for (int i = 0; i < min(3, (int) s_i_list.size()); ++i) result.push_back(sentences[s_i_list[i]]);
        return result;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

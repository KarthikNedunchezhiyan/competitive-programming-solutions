class Solution {
    char getPos(string &word, int pos) {
        return pos < word.length() ? word[pos] : ' ';
    }

public:
    bool validWordSquare(vector<string> &words) {
        const int N = words.size();
        if (words[0].size() != N) return false;

        for (string &word: words) if (word.length() > N) return false;

        for (int i = 0; i < N; ++i)
            for (int j = i; j < N; ++j) if (getPos(words[i], j) != getPos(words[j], i)) return false;

        return true;
    }
};

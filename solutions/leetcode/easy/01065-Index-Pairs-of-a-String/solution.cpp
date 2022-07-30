class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string> &words) {
        vector<vector<int>> result;
        result.reserve(words.size());
        const int textLen = text.length();

        for (string &word: words) {
            const int wordLen = word.length();
            if (wordLen > textLen) continue;

            for (int i = 0; i < textLen - wordLen + 1; i++) {
                if (text[i] == word[0] && text[i + wordLen - 1] == word[wordLen - 1] &&
                    word.compare(text.substr(i, wordLen)) == 0)
                    result.push_back({i, i + wordLen - 1});
            }
        }

        sort(result.begin(), result.end());

        return result;
    }
};

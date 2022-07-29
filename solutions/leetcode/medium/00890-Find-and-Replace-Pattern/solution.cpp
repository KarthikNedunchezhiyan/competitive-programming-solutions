class Solution {
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        vector<string> result;
        const int pLen = pattern.length();
        for (string &word: words) {
            if (word.length() != pLen)
                continue;

            array<short, 52> lookup{};
            lookup.fill(-1);

            int i = 0;
            for (; i < pLen; i++) {
                if (lookup[pattern[i] - 'a'] == -1 && lookup[26 + word[i] - 'a'] == -1) {
                    lookup[pattern[i] - 'a'] = word[i] - 'a';
                    lookup[26 + word[i] - 'a'] = pattern[i] - 'a';
                } else if ((lookup[pattern[i] - 'a'] != word[i] - 'a') ||
                           (lookup[26 + word[i] - 'a'] != pattern[i] - 'a'))
                    break;
            }

            if (i == pLen) result.push_back(word);
        }

        return result;
    }
};

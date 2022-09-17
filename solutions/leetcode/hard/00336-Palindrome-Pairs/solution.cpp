class Solution {
private:
    bool isPalindrome(string_view word, int start, int end) {
        while (start < end)
            if (word[start++] != word[end--]) return false;
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        unordered_map<string_view, int> lookup;

        vector<string> rev_words;
        rev_words.reserve(words.size());
        for (int i = 0; i < words.size(); ++i) {
            lookup[words[i]] = i;
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            rev_words.emplace_back(rev);
        }

        vector<vector<int>> result;
        for (int i = 0; i < words.size(); ++i) {
            const string &word = words[i];

            if (word.empty()) continue;

            // special case
            if (isPalindrome(word, 0, word.length() - 1)) {
                auto it = lookup.find("");
                if (it != lookup.end()) {
                    result.push_back({i, it->second});
                    result.push_back({it->second, i});
                }
            }

            // case 1
            auto it = lookup.find(rev_words[i]);
            if (it != lookup.end() && it->second != i) result.push_back({i, it->second});

            // case 3
            for (int j = word.length() - 1; j > 0; --j) {
                auto it = lookup.find(string_view(rev_words[i]).substr(word.length() - j, j));
                if (it != lookup.end() && isPalindrome(word, j, word.length() - 1))
                    result.push_back({i, it->second});
            }

            // case 2
            for (int j = 0; j < word.length() - 1; ++j) {
                auto it = lookup.find(string_view(rev_words[i]).substr(0, word.length() - j - 1));
                if (it != lookup.end() && isPalindrome(word, 0, j))
                    result.push_back({it->second, i});
            }
        }

        return result;
    }
};

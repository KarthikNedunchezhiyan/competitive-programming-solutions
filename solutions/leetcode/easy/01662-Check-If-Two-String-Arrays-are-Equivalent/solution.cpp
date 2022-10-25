class Solution {
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
        while (!word1.empty() && !word2.empty()) {
            if (word1.back().back() != word2.back().back()) return false;
            word1.back().pop_back();
            word2.back().pop_back();
            
            if (word1.back().empty()) word1.pop_back();
            if (word2.back().empty()) word2.pop_back();
        }

        return word1.empty() && word2.empty();
    }
};

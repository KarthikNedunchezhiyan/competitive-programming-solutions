class Solution {
public:
    bool
    areSentencesSimilar(vector<string> &sentence1, vector<string> &sentence2, vector<vector<string>> &similarPairs) {
        const int N = sentence1.size();
        if (sentence2.size() != N) return false;
        unordered_map<string, unordered_set<string>> lookup;

        for (auto &pair: similarPairs) {
            if (lookup.count(pair[0])) {
                lookup[pair[0]].insert(pair[1]);
                continue;
            }
            lookup[pair[1]].insert(pair[0]);
        }

        for (int i = 0; i < N; ++i) {
            if (sentence1[i] == sentence2[i] || (lookup.count(sentence1[i]) && lookup[sentence1[i]].count(sentence2[i]))
                || (lookup.count(sentence2[i]) && lookup[sentence2[i]].count(sentence1[i])))
                continue;
            return false;
        }

        return true;
    }
};

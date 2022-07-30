class Solution {
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
        vector<string> result;
        array<int, 26> w2_lookup = {0};
        for (string &word: words2) {
            array<int, 26> lookup = {0};
            for (char w: word) w2_lookup[w - 'a'] = max(w2_lookup[w - 'a'], ++lookup[w - 'a']);
        }

        int w2_lookup_total = accumulate(w2_lookup.begin(), w2_lookup.end(), 0);

        for (string &word: words1) {
            array<int, 26> temp;
            copy(w2_lookup.begin(), w2_lookup.end(), temp.begin());
            int lookup_total = w2_lookup_total;

            for (char w: word)
                if (--temp[w - 'a'] >= 0) lookup_total--;

            if (!lookup_total) result.push_back(word);
        }

        return result;
    }
};

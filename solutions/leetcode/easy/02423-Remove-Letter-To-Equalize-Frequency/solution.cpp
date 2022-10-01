class Solution {
private:
    // for cases like aaabbcc
    bool case1(int max_elm_idx, vector<int> &frequency) {
        for (int i = 0; i < frequency.size(); ++i) {
            if (!frequency[i] || i == max_elm_idx) continue;
            if (frequency[i] != (frequency[max_elm_idx] - 1)) return false;
        }

        return true;
    }

    // for cases like aacca
    bool case2(int max_elm_idx, vector<int> &frequency) {
        bool pit_found = false;
        for (int i = 0; i < frequency.size(); ++i) {
            if (!frequency[i] || frequency[i] == frequency[max_elm_idx]) continue;
            if (pit_found || frequency[i] != 1) return false;
            pit_found = true;
        }

        return pit_found;
    }

public:
    bool equalFrequency(string word) {
        vector<int> frequency(26);

        int max_elm_idx = 0;

        for (int i = 0; i < word.length(); ++i)
            if (++frequency[word[i] - 'a'] > frequency[max_elm_idx]) max_elm_idx = word[i] - 'a';

        return (frequency[max_elm_idx] == 1) || case1(max_elm_idx, frequency) || case2(max_elm_idx, frequency);
    }
};

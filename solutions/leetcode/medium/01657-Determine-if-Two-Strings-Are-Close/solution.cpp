class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;
        vector<int> frequency_w1 = vector(26, 0), frequency_w2 = vector(26, 0);
        for (char &c: word1) ++frequency_w1[c - 'a'];
        for (char &c: word2) ++frequency_w2[c - 'a'];

        for (int i = 0; i < 26; ++i)
            if ((frequency_w1[i] && !frequency_w2[i]) || (!frequency_w1[i] && frequency_w2[i])) return false;

        sort(frequency_w1.begin(), frequency_w1.end());
        sort(frequency_w2.begin(), frequency_w2.end());

        return frequency_w1 == frequency_w2;
    }
};

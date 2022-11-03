class Solution {
public:
    int longestPalindrome(vector<string> &words) {
        unordered_map<string, int> frequency;
        for (string &word: words) ++frequency[word];

        int matching_pair = 0;
        bool center_elm = false;

        for (auto &freq: frequency) {
            if (freq.second == 0) continue;

            string rev = freq.first;
            std::reverse(rev.begin(), rev.end());

            if (freq.first == rev) {
                if (freq.second % 2 != 0) {
                    center_elm = true;
                    --freq.second;
                }
                matching_pair += freq.second;
                freq.second = 0;
            } else if (frequency.count(rev) > 0) {
                 int min_freq = min(frequency[rev], freq.second);
                 frequency[rev] -= min_freq;
                 freq.second -= min_freq;

                 matching_pair += min_freq * 2;
            }
        }

        return 2 * (matching_pair + center_elm);
    }
};

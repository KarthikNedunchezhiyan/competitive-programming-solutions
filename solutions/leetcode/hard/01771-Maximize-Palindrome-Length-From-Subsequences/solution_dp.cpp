class Solution {
    int lps(string &word, int l, int r, int bound, int &res, vector<vector<int>> &dp) {
        if (l > r) return 0;
        if (l == r) return 1;

        if (dp[l][r] != -1) return dp[l][r];

        if (word[l] == word[r]) {
            dp[l][r] = 2 + lps(word, l + 1, r - 1, bound, res, dp);
            if (l < bound && r >= bound) res = max(res, dp[l][r]);
            return dp[l][r];
        } else
            return dp[l][r] = max(lps(word, l + 1, r, bound, res, dp), lps(word, l, r - 1, bound, res, dp));
    }

public:
    int longestPalindrome(string word1, string word2) {
        int bound = word1.size(), res = 0;
        word1 += word2;
        vector<vector<int>> dp = vector(word1.size(), vector(word1.size(), -1));
        lps(word1, 0, word1.size() - 1, bound, res, dp);

        return res;
    }
};

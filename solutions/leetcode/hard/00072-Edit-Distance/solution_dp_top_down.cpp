class Solution {
    int min(int a, int b, int c) {
        return (a <= b && a <= c) ? a : (b < c) ? b : c;
    }

    int f(string &word1, string &word2, int w1i, int w2i, vector<vector<int>> &dp) {
        if (w1i == word1.length()) return word2.length() - w2i;
        if (w2i == word2.length()) return word1.length() - w1i;

        if (dp[w1i][w2i] != -1) return dp[w1i][w2i];

        if (word1[w1i] == word2[w2i]) return dp[w1i][w2i] = f(word1, word2, w1i + 1, w2i + 1, dp);

        // replace, insert, delete
        return dp[w1i][w2i] = min(
                f(word1, word2, w1i + 1, w2i + 1, dp),
                f(word1, word2, w1i, w2i + 1, dp),
                f(word1, word2, w1i + 1, w2i, dp)
        ) + 1;
    }

public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp = vector(word1.length(), vector(word2.length(), -1));
        return f(word1, word2, 0, 0, dp);
    }
};

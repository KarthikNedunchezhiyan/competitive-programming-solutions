class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo = vector(text1.size() + 1, vector(text2.size() + 1, 0));


        for (int i = text1.size() - 1; i >= 0; i--) {
            for (int j = text2.size() - 1; j >= 0; j--) {
                memo[i][j] = (text1[i] == text2[j]) ?
                             (1 + memo[i + 1][j + 1]) :
                             max(memo[i + 1][j], memo[i][j + 1]);
            }
        }

        return memo[0][0];
    }
};

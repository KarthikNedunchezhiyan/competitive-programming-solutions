class Solution {
private:
    string text1;
    string text2;
    vector<vector<int>> memo;

    int f(int t1_i, int t2_i) {
        if (t1_i >= text1.size() || t2_i >= text2.size())
            return 0;

        if (memo[t1_i][t2_i] != -1)
            return memo[t1_i][t2_i];

        return memo[t1_i][t2_i] = (text1[t1_i] == text2[t2_i]) ?
                           (1 + f(t1_i + 1, t2_i + 1)) :
                           max(f(t1_i + 1, t2_i), f(t1_i, t2_i + 1));
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        this->text1 = text1;
        this->text2 = text2;
        memo = vector(text1.size(), vector(text2.size(), -1));

        return f(0, 0);
    }
};

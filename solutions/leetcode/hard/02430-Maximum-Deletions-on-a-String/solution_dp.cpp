class Solution {
private:
    int f(int si, string &s, vector<int> &memo, vector<vector<int>> &s_hash) {
        if (si >= s.length()) return 0;

        if (memo[si] != INT_MIN) return memo[si];

        int result = 1;
        for (int i = si + 1; i < s.length() - ((s.length() - si - 1) / 2); ++i)
            if (s_hash[si][i - 1] == s_hash[i][i + (i - si - 1)])
                result = max(result, 1 + f(i, s, memo, s_hash));

        return memo[si] = result;
    }

public:
    int deleteString(string s) {
        vector<int> memo = vector(s.length(), INT_MIN);

        // performing rabin-karp
        vector<vector<int>> s_hash = vector(s.length(), vector(s.length(), -1));
        for (int i = 0; i < s.length(); ++i) {
            int prev = 0;
            for (int j = i; j < s.length(); ++j)
                s_hash[i][j] = prev = ((prev * 27) + s[j]) % 10000007;
        }

        return f(0, s, memo, s_hash);
    }
};

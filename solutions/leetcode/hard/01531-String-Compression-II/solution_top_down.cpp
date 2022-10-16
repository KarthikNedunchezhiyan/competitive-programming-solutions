int memo[100][27][11][100];

class Solution {
    int dfs(string &s, int i, char prev, int prev_c, int k) {
        if (k < 0) return INT_MAX;
        if (i == s.length()) return 0;

        if (memo[i][prev - 'a'][prev_c][k] != -1) return memo[i][prev - 'a'][prev_c][k];

        //keep the index
        int result = dfs(s, i + 1, s[i], s[i] == prev ? min(10, prev_c + 1) : 1, k);
        if (s[i] == prev) result += (prev_c == 1 || prev_c == 9);
        else ++result;

        // comparing with removing index
        return memo[i][prev - 'a'][prev_c][k] = min(result, dfs(s, i + 1, prev, prev_c, k - 1));
    }

public:
    int getLengthOfOptimalCompression(string s, int k) {
        const int N = s.length();
        int i;
        for (i = 1; i < N; ++i) if (s[i] != s[i - 1]) break;
        if (i == N) {
            i -= k;
            return i == 100 ? 4 : i >= 10 ? 3 : i >= 2 ? 2 : i == 1 ? 1 : 0;
        }
        memset(memo, -1, sizeof(memo));
        return dfs(s, 0, '{', 1, k);
    }
};

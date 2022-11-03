#define MOD 1000000007

class Solution {
    int
    f(int i, int j, int k, vector<string> &pizza, vector<vector<int>> &apples_sum, vector<vector<vector<int>>> &memo) {
        if (k == 0) return apples_sum[i][j] ? 1 : 0;

        if (memo[i][j][k] != -1) return memo[i][j][k];

        int result = 0;
        // right cut
        for (int x = j; x < pizza[0].size() - 1; ++x) {
            if ((apples_sum[i][j] - apples_sum[i][x + 1]) && apples_sum[i][x + 1])
                result = (result + f(i, x + 1, k - 1, pizza, apples_sum, memo)) % MOD;
        }

        // bottom cut
        for (int y = i; y < pizza.size() - 1; ++y)
            if ((apples_sum[i][j] - apples_sum[y + 1][j]) && apples_sum[y + 1][j])
                result = (result + f(y + 1, j, k - 1, pizza, apples_sum, memo)) % MOD;

        return memo[i][j][k] = result;
    }

public:
    int ways(vector<string> &pizza, int k) {
        const int R = pizza.size(), C = pizza[0].size();
        vector<vector<int>> apples_sum = vector(R + 1, vector(C + 1, 0));
        vector<vector<vector<int>>> memo = vector(R, vector(C, vector(k, -1)));
        for (int i = R - 1; i >= 0; i--)
            for (int j = C - 1; j >= 0; --j)
                apples_sum[i][j] =
                        (pizza[i][j] == 'A') + apples_sum[i + 1][j] + apples_sum[i][j + 1] - apples_sum[i + 1][j + 1];

        if (apples_sum[0][0] < k) return 0;
        return f(0, 0, k - 1, pizza, apples_sum, memo);
    }
};

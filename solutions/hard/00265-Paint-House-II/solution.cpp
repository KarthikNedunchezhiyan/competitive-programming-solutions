class Solution {
private:
    vector<vector<int>> costs;
    int m, n;
    vector<vector<int>> memo;

    int f(int i, int prev_color) {
        if (i >= m)
            return 0;

        if (prev_color != -1 && memo[i][prev_color] != -1)
            return memo[i][prev_color];

        int result = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (j == prev_color)
                continue;
            result = min(result, costs[i][j] + f(i + 1, j));
        }

        if (prev_color != -1)
            memo[i][prev_color] = result;

        return result;
    }

public:
    int minCostII(vector<vector<int>> &costs) {
        this->costs = costs;
        this->m = costs.size();
        this->n = costs[0].size();
        this->memo = vector(m, vector(n, -1));

        return f(0, -1);
    }
};

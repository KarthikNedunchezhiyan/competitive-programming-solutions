class Solution {
private:
    vector<int> houses;
    vector<vector<int>> cost;
    int m, n;
    vector<vector<vector<int>>> memo;

    int f(int i, int prev_color, int target) {
        if (i >= m)
            return target != 0 ? INT_MAX : 0;

        if (target < 0)
            return INT_MAX;

        if (prev_color != -1 && memo[i][prev_color][target] != -1)
            return memo[i][prev_color][target];

        int result = INT_MAX;

        if (houses[i] != 0)
            result = (prev_color == houses[i] - 1) ? f(i + 1, prev_color, target) : f(i + 1, houses[i] - 1, target - 1);
        else
            for (int j = 0; j < n; j++) {
                int next_min_sum = prev_color == j ? f(i + 1, prev_color, target) : f(i + 1, j, target - 1);
                if (next_min_sum != INT_MAX)
                    result = min(cost[i][j] + next_min_sum, result);
            }

        if (prev_color != -1)
            memo[i][prev_color][target] = result;

        return result;
    }

public:
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target) {
        this->houses = houses;
        this->cost = cost;
        this->m = m;
        this->n = n;
        this->memo = vector(m, vector(n, vector(m + 1, -1)));

        int result = f(0, -1, target);
        return result == INT_MAX ? -1 : result;
    }
};

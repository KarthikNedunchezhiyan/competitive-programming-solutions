#define MOD 1000000007

class Solution {
private:
    long f(int i, int j, vector<vector<int>> &grid, int k, int sum, vector<vector<vector<int>>> &memo) {
        if (i >= grid.size() || j >= grid[0].size()) return 0;

        sum = (sum + grid[i][j]) % k;

        if (memo[i][j][sum] != -1) return memo[i][j][sum];

        if (i == grid.size() - 1 && j == grid[0].size() - 1) return sum % k == 0;

        return memo[i][j][sum] = (f(i + 1, j, grid, k, sum, memo) + f(i, j + 1, grid, k, sum, memo)) % MOD;
    }

public:
    int numberOfPaths(vector<vector<int>> &grid, int k) {
        vector<vector<vector<int>>> memo = vector(grid.size(), vector(grid[0].size(), vector(k, -1)));
        return f(0, 0, grid, k, 0, memo);
    }
};

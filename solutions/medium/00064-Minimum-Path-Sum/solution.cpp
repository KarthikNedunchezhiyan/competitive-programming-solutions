class Solution {
private:
    vector<vector<int>> grid;
    int m, n;
    vector<vector<int>> memo;

    int f(int i, int j) {
        if (i >= m || j >= n)
            return INT_MAX;

        if (memo[i][j] != -1)
            return memo[i][j];

        int further_moves = min(f(i + 1, j), f(i, j + 1));
        further_moves = further_moves == INT_MAX ? 0 : further_moves;
        return memo[i][j] = grid[i][j] + further_moves;
    }

public:
    int minPathSum(vector<vector<int>> &grid) {
        this->grid = grid;
        this->m = grid.size();
        this->n = grid[0].size();
        this->memo = vector(m, vector(n, -1));

        return f(0, 0);
    }
};

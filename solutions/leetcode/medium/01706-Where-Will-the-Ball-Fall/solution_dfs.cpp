class Solution {
    int simulate(int i, int j, vector<vector<int>> &grid, int R, int C) {
        int adj_j = j + grid[i][j];
        if (adj_j < 0 || adj_j == C || grid[i][adj_j] != grid[i][j]) return -1;
        if (i == R - 1) return j + grid[i][j];
        return simulate(i + 1, j + grid[i][j], grid, R, C);
    }

public:
    vector<int> findBall(vector<vector<int>> &grid) {
        const int R = grid.size(), C = grid[0].size();
        vector<int> result;
        for (int j = 0; j < C; ++j)
            result.push_back(simulate(0, j, grid, R, C));

        return result;
    }
};

class Solution {
    bool pathFree(int i, int j, int ydir, int xdir, vector<string> &grid) {
        if (i < 0 || j < 0 || i > grid.size() || j > grid.size()) return true;
        if (grid[i][j] == 'Q') return false;
        return pathFree(i + ydir, j + xdir, ydir, xdir, grid);
    }

    bool isValidPosition(int i, int j, vector<string> &grid) {
        return pathFree(i, j, -1, 0, grid) &&
               pathFree(i, j, -1, -1, grid) &&
               pathFree(i, j, -1, 1, grid);
    }

    void solve(int row, vector<string> &grid, vector<vector<string>> &buffer) {
        if (row >= grid.size()) {
            buffer.emplace_back(grid);
            return;
        }

        for (int j = 0; j < grid[row].size(); ++j)
            if (isValidPosition(row, j, grid)) {
                grid[row][j] = 'Q';
                solve(row + 1, grid, buffer);
                grid[row][j] = '.';
            }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        if(n == 2 || n == 3) return {};
        vector<vector<string>> results;
        vector<string> grid = vector(n, string(n, '.'));
        solve(0, grid, results);
        return results;
    }
};

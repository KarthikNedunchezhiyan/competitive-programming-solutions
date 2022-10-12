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

    int solve(int row, vector<string> &grid) {
        if (row >= grid.size()) return 1;

        int total_ways = 0;
        for (int j = 0; j < grid[row].size(); ++j)
            if (isValidPosition(row, j, grid)) {
                grid[row][j] = 'Q';
                total_ways += solve(row + 1, grid);
                grid[row][j] = '.';
            }

        return total_ways;
    }

public:
    int totalNQueens(int n) {
        if (n == 2 || n == 3) return 0;
        vector<string> grid = vector(n, string(n, '.'));
        return solve(0, grid);
    }
};

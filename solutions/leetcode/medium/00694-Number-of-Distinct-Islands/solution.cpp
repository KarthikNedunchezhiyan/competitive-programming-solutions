class Solution {
private:
    string buffer;

    void floodFill(int i, int j, vector<vector<int>> &grid, char direction_id) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || !grid[i][j]) return;

        grid[i][j] = 0;
        buffer += direction_id;
        floodFill(i, j + 1, grid, 'r');
        floodFill(i + 1, j, grid, 'd');
        floodFill(i, j - 1, grid, 'l');
        floodFill(i - 1, j, grid, 'u');
        buffer += '.';
    }

public:
    Solution() { buffer.reserve(50 * 50); }

    int numDistinctIslands(vector<vector<int>> &grid) {
        unordered_set<string> path_signatures;
        int unique_islands = 0;

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j) {
                buffer.clear();
                floodFill(i, j, grid, 's');
                if (!buffer.empty() && !path_signatures.count(buffer)) {
                    unique_islands++;
                    path_signatures.insert(buffer);
                }
            }

        return unique_islands;
    }
};

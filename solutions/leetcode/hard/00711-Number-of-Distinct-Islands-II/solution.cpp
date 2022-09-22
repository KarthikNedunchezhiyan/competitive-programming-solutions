class Solution {
private:
    string buffer;

    void flipRight(vector<vector<int>> &grid) {
        int m = grid.size(), n = (grid[0].size() + 1) / 2;
        for (int j = 0; j < n; ++j)
            for (int i = 0; i < m; ++i) {
                int temp = grid[i][j];
                grid[i][j] = abs(grid[i][grid[0].size() - 1 - j]);
                grid[i][grid[0].size() - 1 - j] = abs(temp);
            }
    }

    void flipDown(vector<vector<int>> &grid) {
        int m = (grid.size() + 1) / 2, n = grid[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                int temp = grid[i][j];
                grid[i][j] = abs(grid[grid.size() - 1 - i][j]);
                grid[grid.size() - 1 - i][j] = abs(temp);
            }
    }

    void rotate90(vector<vector<int>> &grid) {
        vector<vector<int>> rotate_grid;
        int m = grid.size(), n = grid[0].size();
        for (int j = 0; j < n; ++j) {
            rotate_grid.emplace_back();
            rotate_grid.back().reserve(m);
            for (int i = m - 1; i >= 0; --i)
                rotate_grid.back().emplace_back(abs(grid[i][j]));
        }
        grid = rotate_grid;
    }

    void numberIsland(int i, int j, int num, vector<vector<int>> &grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) return;

        grid[i][j] = num;
        numberIsland(i + 1, j, num, grid);
        numberIsland(i, j + 1, num, grid);
        numberIsland(i - 1, j, num, grid);
        numberIsland(i, j - 1, num, grid);
    }

    void generateFingerPrint(int i, int j, int id, vector<vector<int>> &grid, char direction_id) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= 0) return;

        grid[i][j] *= -1;
        buffer += direction_id;
        generateFingerPrint(i, j + 1, id, grid, 'r');
        generateFingerPrint(i + 1, j, id, grid, 'd');
        generateFingerPrint(i, j - 1, id, grid, 'l');
        generateFingerPrint(i - 1, j, id, grid, 'u');
        buffer += '.';
    }

    void recordFingerPrint(vector<vector<int>> &grid, unordered_map<int, unordered_set<string>> &finger_prints) {
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] > 0) {
                    buffer.clear();
                    int id = grid[i][j];
                    generateFingerPrint(i, j, id, grid, 's');
                    finger_prints[id].insert(buffer);
                }
            }
    }

public:
    int numDistinctIslands2(vector<vector<int>> &grid) {
        int rolling_number = 2, result = 0;

        // distinguished island
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j)
                if (grid[i][j] == 1) numberIsland(i, j, rolling_number++, grid);

        unordered_map<int, unordered_set<string>> finger_prints;

        // 0 degree
        recordFingerPrint(grid, finger_prints);

        // flip right
        flipRight(grid);
        recordFingerPrint(grid, finger_prints);

        // flip down
        flipDown(grid);
        recordFingerPrint(grid, finger_prints);

        // flip right
        flipRight(grid);
        recordFingerPrint(grid, finger_prints);

        // 90 degree
        rotate90(grid);
        recordFingerPrint(grid, finger_prints);

        // flip right
        flipRight(grid);
        recordFingerPrint(grid, finger_prints);

        // flip down
        flipDown(grid);
        recordFingerPrint(grid, finger_prints);

        // flip right
        flipRight(grid);
        recordFingerPrint(grid, finger_prints);

        unordered_set<string> unique_island;

        for (auto &entry: finger_prints) {
            result++;
            for (string finger_print: entry.second)
                if (unique_island.count(finger_print)) {
                    result--;
                    break;
                } else
                    unique_island.insert(finger_print);
        }

        return result;
    }
};

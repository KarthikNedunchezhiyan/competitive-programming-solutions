class Solution {
private:
    vector<pair<int, int>> dirs = {{0, 0},
                                   {0, 1},
                                   {0, 2},
                                   {1, 1},
                                   {2, 0},
                                   {2, 1},
                                   {2, 2}};

    int getSum(int i, int j, vector<vector<int>> &grid) {
        int sum = 0;

        for (pair<int, int> &dir: dirs) {
            int ni = i + dir.first, nj = j + dir.second;
            if (ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size()) return 0;
            sum += grid[ni][nj];
        }

        return sum;
    }

public:
    int maxSum(vector<vector<int>> &grid) {
        int sum = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                sum = max(sum, getSum(i, j, grid));

        return sum;
    }
};

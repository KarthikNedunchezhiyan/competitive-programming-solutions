class Solution {
private:
    vector<pair<int, int>> directions = {{0,  1},
                                         {0,  -1},
                                         {1,  0},
                                         {-1, 0}};

    void traverse(int i, int j, vector<vector<int>> &grid, queue<int> &buffer, unordered_set<int> &visited) {
        while (!(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())) {
            int linear_index = (i * grid[0].size()) + j;
            if (visited.count(linear_index)) return;

            visited.emplace(linear_index);
            buffer.emplace(linear_index);

            auto &dir = directions[grid[i][j] - 1];
            i += dir.first;
            j += dir.second;
        }
    }

public:
    int minCost(vector<vector<int>> &grid) {
        queue<int> bfs;
        unordered_set<int> visited;
        traverse(0, 0, grid, bfs, visited);

        int distance = 0;

        while (!bfs.empty()) {
            int bfs_size = bfs.size();

            while (bfs_size--) {
                int i = (bfs.front() / grid[0].size()), j = bfs.front() % grid[0].size();
                if (i == grid.size() - 1 && j == grid[0].size() - 1) return distance;
                bfs.pop();

                for (int dir = 0; dir < directions.size(); ++dir) {
                    int new_i = i + directions[dir].first, new_j = j + directions[dir].second;
                    traverse(new_i, new_j, grid, bfs, visited);
                }
            }
            ++distance;
        }

        return -1;
    }
};

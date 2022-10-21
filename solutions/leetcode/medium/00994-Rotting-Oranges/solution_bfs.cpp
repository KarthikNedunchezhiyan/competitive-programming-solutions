class Solution {
    vector<pair<int, int>> dirs = {{1,  0},
                                   {0,  1},
                                   {-1, 0},
                                   {0,  -1}};
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int R = grid.size(), C = grid[0].size();
        queue<int> bfs;
        int time_taken = 0, total_fresh_left = 0;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 2) bfs.emplace((i * C) + j);
                else if (grid[i][j]) ++total_fresh_left;
            }

        while (!bfs.empty()) {
            int bfs_size = bfs.size();
            while (bfs_size--) {
                int i = bfs.front() / C, j = bfs.front() % C;
                bfs.pop();
                for (auto dir: dirs) {
                    int ni = dir.first + i, nj = dir.second + j;
                    if (ni < 0 || nj < 0 || ni >= R || nj >= C || grid[ni][nj] != 1) continue;
                    grid[ni][nj] = 2;
                    --total_fresh_left;
                    bfs.emplace((ni * C) + nj);
                }
            }
            ++time_taken;
        }

        return total_fresh_left > 0 ? -1 : !time_taken ? 0 : time_taken - 1;
    }
};

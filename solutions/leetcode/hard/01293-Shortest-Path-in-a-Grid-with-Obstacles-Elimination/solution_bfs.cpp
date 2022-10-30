class Solution {
    vector<pair<int, int>> dirs = {{1,  0},
                                   {0,  1},
                                   {-1, 0},
                                   {0,  -1}};

    bool isManhattanDistPossible(vector<vector<int>> &grid, int R, int C, int k) {
        int brickDR = 0, brickRD = 0;
        for (int i = 0; i < R; ++i) {
            if (grid[i][0]) ++brickDR;
            if (grid[i][C - 1])++brickRD;
        }
        for (int j = 1; j < C; ++j) {
            if (grid[R - 1][j]) ++brickDR;
            if (grid[0][C - 1 - j]) ++brickRD;
        }

        return brickDR <= k || brickRD <= k;
    }

public:
    int shortestPath(vector<vector<int>> &grid, int k) {
        // co-ordinate, obstacles_left
        const int R = grid.size(), C = grid[0].size();
        if (isManhattanDistPossible(grid, R, C, k)) return R + C - 2;

        queue<pair<int, int>> bfs;
        vector<vector<int>> memo = vector(R, vector(C, -1));
        bfs.emplace(0, k);
        int distance = 1;

        while (!bfs.empty()) {
            int bfs_size = bfs.size();
            while (bfs_size--) {
                int i = bfs.front().first / C, j = bfs.front().first % C, k_left = bfs.front().second;

                bfs.pop();
                for (auto dir: dirs) {
                    int ni = i + dir.first, nj = j + dir.second;
                    if (ni < 0 || nj < 0 || ni >= R || nj >= C) continue;
                    int n_left = k_left - grid[ni][nj];
                    if (n_left < 0 || memo[ni][nj] >= n_left) continue;
                    memo[ni][nj] = n_left;
                    if (ni == (R - 1) && nj == (C - 1)) return distance;
                    bfs.emplace((ni * C) + nj, n_left);
                }
            }
            ++distance;
        }
        return -1;
    }
};

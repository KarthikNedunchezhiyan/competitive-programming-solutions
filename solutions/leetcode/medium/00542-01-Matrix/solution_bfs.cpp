class Solution {
    vector<pair<int, int>> dirs = {{1,  0},
                                   {0,  1},
                                   {-1, 0},
                                   {0,  -1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        const int R = mat.size(), C = mat[0].size();
        queue<int> bfs;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (!mat[i][j]) bfs.emplace((i * C) + j);
                else mat[i][j] = -1;

        int distance = 1;
        while (!bfs.empty()) {
            int bfs_size = bfs.size();
            while (bfs_size--) {
                int i = bfs.front() / C, j = bfs.front() % C;
                bfs.pop();
                for (auto dir: dirs) {
                    int ni = i + dir.first, nj = j + dir.second;
                    if (ni >= R || ni < 0 || nj >= C || nj < 0 || mat[ni][nj] >= 0) continue;
                    mat[ni][nj] = distance;
                    bfs.push((ni * C) + nj);
                }
            }
            ++distance;
        }

        return mat;
    }
};

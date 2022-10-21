class Solution {
private:
    vector<pair<int, int>> directions = {{1,  0},
                                         {0,  1},
                                         {-1, 0},
                                         {0,  -1}};
public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        const int R = rooms.size(), C = rooms[0].size();
        queue<int> bfs;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (!rooms[i][j]) bfs.emplace((i * C) + j);

        int distance = 1;
        while (!bfs.empty()) {
            int bfs_size = bfs.size();
            while (bfs_size--) {
                int i = bfs.front() / C, j = bfs.front() % C;
                bfs.pop();

                for (auto dir: directions) {
                    int ni = i + dir.first, nj = j + dir.second;

                    if (ni < 0 || nj < 0 || ni >= R || nj >= C || rooms[ni][nj] != INT_MAX) continue;
                    rooms[ni][nj] = distance;
                    bfs.emplace((ni * C) + nj);
                }
            }
            ++distance;
        }
    }
};


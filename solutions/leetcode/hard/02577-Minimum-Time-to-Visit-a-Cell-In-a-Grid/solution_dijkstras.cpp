vector<pair<int, int>> directions = {{1,  0},
                                     {0,  1},
                                     {-1, 0},
                                     {0,  -1}};

class Solution {
    int ctoi(int i, int j, int C) {
        return (i * C) + j;
    }

public:
    int minimumTime(vector<vector<int>> &grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        const int R = grid.size(), C = grid[0].size();
        vector<vector<bool>> visited = vector(R, vector(C, false));

        // value, co-ordinate
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            int i = pq.top().second / C, j = pq.top().second % C, time = pq.top().first;
            pq.pop();

            if (visited[i][j]) continue;
            visited[i][j] = true;

            if (i == R - 1 && j == C - 1) return time;

            for (auto &dir: directions) {
                int ni = i + dir.first, nj = j + dir.second, nt = time + 1;
                if (ni < 0 || nj < 0 || ni >= R || nj >= C || visited[ni][nj]) continue;

                if (grid[ni][nj] > time) {
                    int diff = grid[ni][nj] - time;
                    if (diff % 2 == 0) nt = grid[ni][nj] + 1;
                    else nt = grid[ni][nj];
                }

                pq.emplace(nt, ctoi(ni, nj, C));
            }
        }

        // control cannot reach here
        return -1;
    }
};


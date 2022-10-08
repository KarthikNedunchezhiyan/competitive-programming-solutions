class Solution {
private:
    vector<pair<int, int>> directions = {{1,  0},
                                         {0,  1},
                                         {-1, 0},
                                         {0,  -1}};
public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        queue<pair<int, int>> bfs;

        for (int i = 0; i < rooms.size(); ++i)
            for (int j = 0; j < rooms[0].size(); ++j)
                if (rooms[i][j] == 0) bfs.emplace(i, j);

        while (!bfs.empty()) {
            pair<int, int> c = bfs.front();
            bfs.pop();

            for (auto dir: directions) {
                int i = c.first + dir.first, j = c.second + dir.second, dist = rooms[c.first][c.second] + 1;

                if (i < 0 || j < 0 || i >= rooms.size() || j >= rooms[0].size() || rooms[i][j] != INT_MAX) continue;
                rooms[i][j] = dist;
                bfs.emplace(i, j);
            }
        }
    }
};

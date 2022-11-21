class Solution {
    vector<pair<int, int>> directions = {{1,  0},
                                         {0,  1},
                                         {-1, 0},
                                         {0,  -1}};

    int ctoi(int i, int j, int C) {
        return (i * C) + j;
    }

public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        int R = maze.size(), C = maze[0].size();
        queue<int> bfs;
        bfs.push(ctoi(entrance[0], entrance[1], C));
        maze[entrance[0]][entrance[1]] = '+';
        int distance = 1;
        while (!bfs.empty()) {
            int bfs_size = bfs.size();

            while (bfs_size--) {
                int i = bfs.front() / C, j = bfs.front() % C;
                bfs.pop();

                for (auto dir: directions) {
                    int new_i = i + dir.first, new_j = j + dir.second;
                    if (new_i < 0 || new_j < 0 || new_i >= R || new_j >= C || maze[new_i][new_j] == '+') continue;
                    if (!new_i || !new_j || new_i == R - 1 || new_j == C - 1) return distance;
                    maze[new_i][new_j] = '+';
                    bfs.push(ctoi(new_i, new_j, C));
                }
            }
            ++distance;
        }

        return -1;
    }
};

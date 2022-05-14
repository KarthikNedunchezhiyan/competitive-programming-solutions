class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        int n = grid.size();

        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        if (n == 1)
            return 1;

        queue<pair<int, int>> bfsQ;
        grid[0][0] = 1;
        bfsQ.push(pair(0, 0));

        vector<pair<int, int>> directions = {pair(-1, -1), pair(-1, 0), pair(-1, 1), pair(0, -1), pair(0, 1),
                                             pair(1, -1), pair(1, 0), pair(1, 1)};

        while (!bfsQ.empty()) {
            pair<int, int> currentCell = bfsQ.front();
            bfsQ.pop();
            int distanceTraveled = grid[currentCell.first][currentCell.second];

            for (pair<int, int> direction: directions) {
                int neighbour_i = currentCell.first + direction.first;
                int neighbour_j = currentCell.second + direction.second;

                if (neighbour_i < 0 || neighbour_j < 0 || neighbour_i >= n || neighbour_j >= n ||
                    grid[neighbour_i][neighbour_j] > 0)
                    continue;

                if (neighbour_i == n - 1 && neighbour_j == n - 1)
                    return distanceTraveled + 1;

                grid[neighbour_i][neighbour_j] = distanceTraveled + 1;
                bfsQ.push(pair(neighbour_i, neighbour_j));
            }
        }

        return -1;
    }
};

typedef pair<int, int> coordinates;

class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int freshOranges = 0, totalTime = 0;
        vector<coordinates> directions = {pair(-1, 0), pair(0, -1), pair(0, 1), pair(1, 0)};
        queue<coordinates> bfsQ;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 2)
                    bfsQ.push(pair(i, j));
                else if (grid[i][j] == 1)
                    freshOranges++;


        while (!bfsQ.empty()) {
            int queueSize = bfsQ.size();
            while (queueSize-- > 0) {
                coordinates firstCo = bfsQ.front();
                bfsQ.pop();

                for (coordinates direction: directions) {
                    int neighbourI = firstCo.first + direction.first;
                    int neighbourJ = firstCo.second + direction.second;

                    if (neighbourI < 0 || neighbourJ < 0 || neighbourI >= m || neighbourJ >= n ||
                        grid[neighbourI][neighbourJ] != 1)
                        continue;

                    grid[neighbourI][neighbourJ] = 2;
                    freshOranges--;
                    bfsQ.push(pair(neighbourI, neighbourJ));
                }
            }

            if (bfsQ.size() != 0) totalTime++;
        }

        return freshOranges == 0 ? totalTime : -1;
    }
};

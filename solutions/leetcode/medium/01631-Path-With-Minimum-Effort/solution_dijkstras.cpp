typedef pair<int, int> coordinate;
// abs_height, coordinate
typedef pair<int, coordinate> pQItem;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int ROW = heights.size(), COL = heights[0].size(), result = INT_MIN;
        vector<coordinate> directions = {{-1, 0},
                                         {0,  -1},
                                         {0,  1},
                                         {1,  0}};

        priority_queue<pQItem, vector<pQItem>, greater<>> pQ;
        pQ.push({0, {0, 0}});

        while (!pQ.empty()) {
            pQItem item = pQ.top();
            pQ.pop();

            if (heights[item.second.first][item.second.second] == -1)
                continue;

            result = max(result, item.first);

            if ((item.second.first == ROW - 1) && (item.second.second == COL - 1))
                return result;

            int currentHeight = heights[item.second.first][item.second.second];
            heights[item.second.first][item.second.second] = -1;

            for (coordinate direction: directions) {
                int newI = item.second.first + direction.first, newJ = item.second.second + direction.second;
                if (!(newI < 0 || newI >= ROW || newJ < 0 || newJ >= COL || heights[newI][newJ] == -1))
                    pQ.push({abs(currentHeight - heights[newI][newJ]), {newI, newJ}});
            }
        }

        return -1;
    }
};

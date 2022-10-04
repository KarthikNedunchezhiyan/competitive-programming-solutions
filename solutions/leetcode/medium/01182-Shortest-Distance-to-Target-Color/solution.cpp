#define inc(x) (x != INT_MAX) ? ++x : x

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int> &colors, vector<vector<int>> &queries) {
        vector<vector<int>> memo = vector(colors.size(), vector(3, -1));

        vector<int> buffer = vector(3, INT_MAX);

        for (int i = 0; i < colors.size(); ++i) {
            buffer[colors[i] - 1] = -1;
            memo[i][0] = inc(buffer[0]);
            memo[i][1] = inc(buffer[1]);
            memo[i][2] = inc(buffer[2]);
        }

        buffer[0] = buffer[1] = buffer[2] = INT_MAX;

        for (int i = colors.size() - 1; i >= 0; --i) {
            buffer[colors[i] - 1] = -1;
            memo[i][0] = min(memo[i][0], inc(buffer[0]));
            memo[i][1] = min(memo[i][1], inc(buffer[1]));
            memo[i][2] = min(memo[i][2], inc(buffer[2]));
        }

        vector<int> result;
        result.reserve(queries.size());

        for (auto query: queries)
            result.emplace_back(memo[query[0]][query[1] - 1] == INT_MAX ? -1 : memo[query[0]][query[1] - 1]);

        return result;
    }
};

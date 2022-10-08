class Solution {
private:
    vector<pair<int, int>> directions = {{1,  0},
                                         {0,  1},
                                         {-1, 0},
                                         {0,  -1}};

    void search(int i, int j, vector<vector<int>> &heights, vector<vector<int>> &memo, int ocean_code) {
        if (memo[i][j] <= ocean_code) return;

        memo[i][j] += ocean_code;

        for (auto dir: directions) {
            int new_i = i + dir.first, new_j = j + dir.second;

            if (new_i < 0 || new_j < 0 || new_i >= heights.size() || new_j >= heights[0].size() ||
                heights[new_i][new_j] < heights[i][j])
                continue;

            search(new_i, new_j, heights, memo, ocean_code);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        vector<vector<int>> memo = vector(heights.size(), vector(heights[0].size(), 0));
        vector<vector<int>> result;

        for (int i = 0; i < heights.size(); ++i)
            search(i, 0, heights, memo, -1);

        for (int j = 0; j < heights[0].size(); ++j)
            search(0, j, heights, memo, -1);

        for (int i = 0; i < heights.size(); ++i)
            search(i, heights[0].size() - 1, heights, memo, -2);

        for (int j = 0; j < heights[0].size(); ++j)
            search(heights.size() - 1, j, heights, memo, -2);

        for (int i = 0; i < heights.size(); ++i)
            for (int j = 0; j < heights[0].size(); ++j)
                if (memo[i][j] <= -3) result.push_back({i, j});

        return result;
    }
};

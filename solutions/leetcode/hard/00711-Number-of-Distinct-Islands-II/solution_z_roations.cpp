class Solution {
    void extractShape(int i, int j, vector<vector<int>> &grid, vector<pair<int, int>> &buffer) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || !grid[i][j]) return;

        grid[i][j] = 0;
        buffer.emplace_back(i, j);
        extractShape(i, j + 1, grid, buffer);
        extractShape(i + 1, j, grid, buffer);
        extractShape(i, j - 1, grid, buffer);
        extractShape(i - 1, j, grid, buffer);
    }

    vector<pair<int, int>> &normalize(vector<pair<int, int>> &buffer) {
        sort(buffer.begin(), buffer.end());
        for (int i = buffer.size() - 1; i >= 0; --i) {
            buffer[i].first -= buffer[0].first;
            buffer[i].second -= buffer[0].second;
        }

        return buffer;
    }

    void transformAndNormalize(vector<pair<int, int>> &buffer, set<vector<pair<int, int>>> &distinct_island) {
        vector<vector<pair<int, int>>> transforms(7);
        for (int i = 0; i < buffer.size(); ++i) {
            const int x = buffer[i].first, y = buffer[i].second;
            transforms[0].push_back({-x, y});
            transforms[1].push_back({x, -y});
            transforms[2].push_back({-x, -y});
            transforms[3].push_back({y, x});
            transforms[4].push_back({-y, x});
            transforms[5].push_back({y, -x});
            transforms[6].push_back({-y, -x});
        }

        for (int i = 0; i < transforms.size(); ++i)
            distinct_island.insert(normalize(transforms[i]));
    }

public:
    int numDistinctIslands2(vector<vector<int>> &grid) {
        set<vector<pair<int, int>>> distinct_island;
        const int M = grid.size(), N = grid[0].size();
        int distinct_island_count = 0;

        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j) {
                if (grid[i][j]) {
                    vector<pair<int, int>> buffer;
                    extractShape(i, j, grid, buffer);
                    if (distinct_island.count(normalize(buffer))) continue;

                    ++distinct_island_count;
                    distinct_island.insert(buffer);
                    // add all possible z rotations;
                    transformAndNormalize(buffer, distinct_island);
                }
            }

        return distinct_island_count;
    }
};

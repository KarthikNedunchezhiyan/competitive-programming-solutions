class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);

        for (int i = 0; i < numRows; ++i) {
            result[i].reserve(i + 1);
            for (int j = 0; j < i + 1; ++j)
                result[i].emplace_back((j == 0 || j == i) ? 1 : result[i - 1][j - 1] + result[i - 1][j]);
        }

        return result;
    }
};

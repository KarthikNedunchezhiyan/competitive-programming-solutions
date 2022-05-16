class Solution {
private:
    vector<vector<int>> matrix;
    int m, n;
    vector<vector<int>> memo;

    int f(int i, int j) {
        if (i >= m || j >= n || i < 0 || j < 0)
            return INT_MAX;

        if (memo[i][j] != -1)
            return memo[i][j];

        int further_moves = min({f(i + 1, j - 1), f(i + 1, j), f(i + 1, j + 1)});
        further_moves = further_moves == INT_MAX ? 0 : further_moves;
        return memo[i][j] = matrix[i][j] + further_moves;
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        this->matrix = matrix;
        this->m = matrix.size();
        this->n = matrix[0].size();
        this->memo = vector(m, vector(n, -1));

        int result = INT_MAX;
        for (int i = 0; i < n; i++)
            result = min(result, f(0, i));
        
        return result;
    }
};

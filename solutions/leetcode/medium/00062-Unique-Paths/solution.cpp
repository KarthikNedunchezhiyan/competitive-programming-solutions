class Solution {
private:
    int m, n;
    vector<vector<int>> memo;

    int f(int i, int j) {
        if (i >= m || j >= n)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (memo[i][j] != -1)
            return memo[i][j];

        return memo[i][j] = f(i + 1, j) + f(i, j + 1);
    }

public:
    int uniquePaths(int m, int n) {
        this->m = m;
        this->n = n;
        this->memo = vector(m, vector(n, -1));
        return f(0, 0);
    }
};

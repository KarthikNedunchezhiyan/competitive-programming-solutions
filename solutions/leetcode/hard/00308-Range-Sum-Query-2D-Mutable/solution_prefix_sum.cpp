class NumMatrix {
private:
    vector<vector<int>> pre_sum, *matrix;

    int sum_till(int row, int col) {
        if (row < 0 || col < 0) return 0;
        int result = pre_sum[row][col];
        for (int i = 0; i < row; i++)
            result += pre_sum[i][col];
        return result;
    }

public:
    NumMatrix(vector<vector<int>> &matrix) {
        this->matrix = &matrix;
        pre_sum.reserve(matrix.size());
        for (int i = 0; i < matrix.size(); i++) {
            pre_sum.emplace_back();
            pre_sum[i].reserve(matrix[i].size());
            for (int j = 0; j < matrix[i].size(); j++)
                pre_sum[i].push_back(j == 0 ? matrix[i][j] : matrix[i][j] + pre_sum[i][j - 1]);
        }
    }

    void update(int row, int col, int val) {
        int diff = (*matrix)[row][col] - val;
        (*matrix)[row][col] = val;
        for (int j = col; j < pre_sum[row].size(); j++)
            pre_sum[row][j] -= diff;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum_till(row2, col2) - sum_till(row1 - 1, col2) - sum_till(row2, col1 - 1) +
               sum_till(row1 - 1, col1 - 1);
    }
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */

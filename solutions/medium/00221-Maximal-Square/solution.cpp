class Solution {
private:
    vector<vector<int>> memo;
    vector<vector<char>> matrix;

    int findMaxSquare(int i, int j) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[i].size() || matrix[i][j] == '0') {
            return 0;
        }

        if (memo[i][j] != -1)
            return memo[i][j];

        int diag_square = findMaxSquare(i - 1, j - 1);
        int up_square = findMaxSquare(i - 1, j);
        int left_square = findMaxSquare(i, j - 1);

        return memo[i][j] = (up_square == diag_square && left_square == diag_square) ?
                            diag_square + 1 :
                            min({diag_square, up_square, left_square}) + 1;
    }

public:
    int maximalSquare(vector<vector<char>> &matrix) {
        this->matrix = matrix;
        this->memo = vector(matrix.size(), vector(matrix[0].size(), -1));

        int max_square_size = 0;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++) {
                max_square_size = max(max_square_size, findMaxSquare(i, j));
            }

        return max_square_size * max_square_size;
    }
};

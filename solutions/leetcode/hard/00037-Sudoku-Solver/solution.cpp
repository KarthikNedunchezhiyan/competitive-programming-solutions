class Solution {
    vector<int> rows = vector(9, 0);
    vector<int> cols = vector(9, 0);
    vector<int> squares = vector(9, 0);

    int cvtSquareIndex(int i, int j) {
        return ((i / 3) * 3) + (j / 3);
    }

    bool isAllowed(int i, int j, int val) {
        int mask = 1 << val;
        return !((rows[i] & mask) || (cols[j] & mask) || (squares[cvtSquareIndex(i, j)] & mask));
    }

    void addMask(int i, int j, int val) {
        int mask = 1 << val;
        rows[i] |= mask;
        cols[j] |= mask;
        squares[cvtSquareIndex(i, j)] |= mask;
    }

    void removeMask(int i, int j, int val) {
        int mask = ~(1 << val);
        rows[i] &= mask;
        cols[j] &= mask;
        squares[cvtSquareIndex(i, j)] &= mask;
    }

    bool solve(vector <vector<char>> &board) {
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; ++k) {
                        if (isAllowed(i, j, k)) {
                            addMask(i, j, k);
                            board[i][j] = '0' + k;
                            if (solve(board)) return true;
                            removeMask(i, j, k);
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
        return true;
    }

public:
    void solveSudoku(vector <vector<char>> &board) {
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] != '.') addMask(i, j, board[i][j] - '0');
        solve(board);
    }
};

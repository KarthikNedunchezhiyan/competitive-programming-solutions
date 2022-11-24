class Solution {
    bool _exist(int i, int j, int w_i, int R, int C, vector<vector<char>> &board, string &word) {
        if (w_i == word.length()) return true;
        if (i < 0 || j < 0 || i >= R || j >= C || board[i][j] != word[w_i]) return false;
        board[i][j] = board[i][j] - 50;
        bool result = _exist(i + 1, j, w_i + 1, R, C, board, word) || _exist(i, j + 1, w_i + 1, R, C, board, word) ||
                      _exist(i - 1, j, w_i + 1, R, C, board, word) || _exist(i, j - 1, w_i + 1, R, C, board, word);
        board[i][j] = board[i][j] + 50;
        return result;
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        const int R = board.size(), C = board[0].size();
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j) if (_exist(i, j, 0, R, C, board, word)) return true;
        return false;
    }
};

#define BOARD_SIZE 9

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int lookup[3][BOARD_SIZE] = {0};

        for (int i = 0; i < BOARD_SIZE; ++i)
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == '.') continue;

                int mask = 1 << (board[i][j] - '1'), box_index = ((i / 3) * 3) + (j / 3);;

                if (lookup[0][i] & mask || lookup[1][j] & mask || lookup[2][box_index] & mask) return false;

                lookup[0][i] |= mask;
                lookup[1][j] |= mask;
                lookup[2][box_index] |= mask;
            }

        return true;
    }
};

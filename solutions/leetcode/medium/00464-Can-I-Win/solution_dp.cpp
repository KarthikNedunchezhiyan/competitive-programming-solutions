class Solution {
    int maxChoosableInteger;
    vector<int> memo = vector(1 << 20, -1);

    bool _canIWin(int state, int desired_total) {
        if (desired_total <= 0) return true;

        if (memo[state] != -1) return memo[state];

        for (int i = maxChoosableInteger; i > 0; i--)
            if ((state & (1 << (i - 1))) == 0 && _canIWin(state | (1 << (i - 1)), desired_total - i))
                return memo[state] = false;

        return memo[state] = true;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((maxChoosableInteger * (maxChoosableInteger + 1)) / 2 < desiredTotal)
            return false;

        if (!desiredTotal) return true;

        this->maxChoosableInteger = maxChoosableInteger;

        return !_canIWin(0, desiredTotal);
    }
};

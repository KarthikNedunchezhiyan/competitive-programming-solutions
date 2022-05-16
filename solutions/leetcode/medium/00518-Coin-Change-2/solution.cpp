class Solution {
private:
    vector<int> coins;
    vector<vector<int>> memo;

    int f(int amount, int c_index) {
        if (amount == 0)
            return 1;

        if (amount < 0 || c_index >= coins.size())
            return 0;

        if (memo[amount][c_index] != -1)
            return memo[amount][c_index];

        return memo[amount][c_index] = f(amount - coins[c_index], c_index) + f(amount, c_index + 1);
    }

public:
    int change(int amount, vector<int> &coins) {
        this->coins = coins;
        this->memo = vector(amount + 1, vector(coins.size(), -1));
        return f(amount, 0);
    }
};

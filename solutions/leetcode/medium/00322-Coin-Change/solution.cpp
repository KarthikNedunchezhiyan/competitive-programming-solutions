class Solution {
private:
    vector<int> coins;
    vector<vector<int>> memo;

    int f(int i, int amount_left) {
        if (amount_left == 0)
            return 0;

        if (amount_left < 0 || i >= coins.size())
            return INT_MAX;

        if (memo[i][amount_left] != -1)
            return memo[i][amount_left];

        int skipped = f(i + 1, amount_left);
        int included = f(i, amount_left - coins[i]);

        return memo[i][amount_left] = min(skipped == INT_MAX ? INT_MAX : skipped,
                                          included == INT_MAX ? INT_MAX : 1 + included);
    }

public:
    int coinChange(vector<int> &coins, int amount) {
        this->coins = coins;
        this->memo = vector(coins.size() + 1, vector(amount + 1, -1));
        int result = f(0, amount);
        return result == INT_MAX ? -1 : result;
    }
};

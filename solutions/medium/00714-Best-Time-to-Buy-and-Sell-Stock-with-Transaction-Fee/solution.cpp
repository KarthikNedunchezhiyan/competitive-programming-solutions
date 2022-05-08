class Solution {
private:
    vector<int> prices;
    int fee;
    vector<vector<int>> memo;

    int f(int i, bool buy) {
        if (i >= prices.size())
            return 0;

        if (memo[i][buy] != -1)
            return memo[i][buy];

        if (buy)
            return memo[i][buy] = max(f(i + 1, buy), f(i + 1, !buy) - prices[i]);

        return memo[i][buy] = max(f(i + 1, buy), f(i + 1, !buy) + prices[i] - fee);
    }

public:
    int maxProfit(vector<int> &prices, int fee) {
        this->prices = prices;
        this->fee = fee;
        this->memo = vector(prices.size(), vector(2, -1));

        return f(0, true);
    }
};

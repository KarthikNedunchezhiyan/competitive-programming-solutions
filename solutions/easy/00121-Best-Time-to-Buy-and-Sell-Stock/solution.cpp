class Solution {
private:
    vector<int> prices;
    vector<vector<int>> memo;

    int f(int pi, bool buy) {
        if (pi >= prices.size())
            return 0;

        if (memo[pi][buy] != INT_MIN)
            return memo[pi][buy];

        if (buy)
            return memo[pi][buy] = max(f(pi + 1, buy), f(pi + 1, !buy) - prices[pi]);

        return memo[pi][buy] = max(f(pi + 1, buy), prices[pi]);
    }

public:
    int maxProfit(vector<int> &prices) {
        this->prices = prices;
        this->memo = vector(prices.size(), vector(2, INT_MIN));
        return f(0, true);
    }
};

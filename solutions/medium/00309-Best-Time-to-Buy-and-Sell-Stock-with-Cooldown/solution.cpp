class Solution {
private:
    vector<int> prices;
    vector<vector<int>> memo;

    int f(int start_index, bool buy) {
        if (start_index >= prices.size())
            return 0;

        if (memo[start_index][buy] != -1)
            return memo[start_index][buy];

        if (buy)
            return memo[start_index][buy] = max(f(start_index + 1, !buy) - prices[start_index],
                                                f(start_index + 1, buy));

        return memo[start_index][buy] = max(f(start_index + 2, !buy) + prices[start_index],
                                            f(start_index + 1, buy));
    }

public:
    int maxProfit(vector<int> &prices) {
        this->prices = prices;
        this->memo = vector(prices.size() + 1, vector(2, -1));

        return f(0, true);
    }
};

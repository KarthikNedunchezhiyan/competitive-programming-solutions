class Solution {
    int mP(int cursor, vector<int> &prices, int trans_left, bool buy, vector<vector<vector<int>>> &memo) {
        if (cursor == prices.size() || !trans_left) return 0;

        if (memo[cursor][trans_left - 1][buy] != INT_MIN) return memo[cursor][trans_left - 1][buy];

        int include;
        if (buy) include = mP(cursor + 1, prices, trans_left, !buy, memo) - prices[cursor];
        else include = mP(cursor + 1, prices, trans_left - 1, !buy, memo) + prices[cursor];

        return memo[cursor][trans_left - 1][buy] = max(include, mP(cursor + 1, prices, trans_left, buy, memo));
    }

public:
    int maxProfit(vector<int> &prices) {
        vector<vector<vector<int>>> memo = vector(prices.size(), vector(2, vector(2, INT_MIN)));
        return mP(0, prices, 2, true, memo);
    }
};

class Solution {
private:
    vector<int> prices;
    vector<vector<int>> memo;

    int f(int start_index, int trans_left, bool buy) {
        if (start_index >= prices.size() || trans_left == 0)
            return 0;

        int memo_y_key = buy << 7 | trans_left;

        if (memo[start_index][memo_y_key] != -1)
            return memo[start_index][memo_y_key];

        if (buy)
            return memo[start_index][memo_y_key] = max(f(start_index + 1, trans_left, !buy) - prices[start_index],
                                                       f(start_index + 1, trans_left, buy));

        return memo[start_index][memo_y_key] = max(f(start_index + 1, trans_left - 1, !buy) + prices[start_index],
                                                   f(start_index + 1, trans_left, buy));
    }

public:
    int maxProfit(int k, vector<int> &prices) {
        this->prices = prices;
        // 2^8 = 256. 2^7 to store trans_left (100 is max limit as per question) and 2^1 for buy bool.
        this->memo = vector(prices.size() + 1, vector(260, -1));

        return f(0, k, true);
    }
};

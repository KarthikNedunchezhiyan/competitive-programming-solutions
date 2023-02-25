class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0, next_high_price = -1;
        for (auto it = prices.rbegin(); it != prices.rend(); it++) {
            next_high_price = max(next_high_price, *it);
            profit = max(profit, next_high_price - *it);
        }
        return profit;
    }
};

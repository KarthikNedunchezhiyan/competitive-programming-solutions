class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int max_val = prices.back(), profit = 0;
        for (int i = prices.size() - 2; i >= 0; --i) {
            max_val = max(max_val, prices[i]);
            if (prices[i] < max_val && (max_val - prices[i]) > profit) profit = max_val - prices[i];
        }

        return profit;
    }
};

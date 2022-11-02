class Solution {
public:
    int maxProfit(vector<int> &prices) {
        const int N = prices.size();
        vector<vector<int>> prev = vector(2, vector(2, 0));
        vector<vector<int>> current = vector(2, vector(2, 0));

        for (int i = N - 1; i >= 0; --i) {
            for (int trans_left = 0; trans_left < 2; ++trans_left) {
                // buy
                int include = prev[trans_left][false] - prices[i];
                current[trans_left][true] = max(include, prev[trans_left][true]);
                // sell
                include = (!trans_left ? 0 : prev[trans_left - 1][true]) + prices[i];
                current[trans_left][false] = max(include, prev[trans_left][false]);
            }
            prev = current;
        }

        return prev[1][true];
    }
};

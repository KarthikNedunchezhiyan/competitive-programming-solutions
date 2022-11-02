class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        const int N = prices.size();
        vector<vector<int>> prev = vector(k, vector(2, 0));
        vector<vector<int>> current = prev;

        for (int i = N - 1; i >= 0; --i) {
            for (int trans_left = 0; trans_left < k; ++trans_left) {
                // buy
                int include = prev[trans_left][false] - prices[i];
                current[trans_left][true] = max(include, prev[trans_left][true]);
                // sell
                include = (!trans_left ? 0 : prev[trans_left - 1][true]) + prices[i];
                current[trans_left][false] = max(include, prev[trans_left][false]);
            }
            prev = current;
        }

        return prev[k-1][true];
    }
};

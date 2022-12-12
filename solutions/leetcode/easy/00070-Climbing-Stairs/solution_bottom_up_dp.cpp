vector<int> dp = {1, 2};

class Solution {
public:
    int climbStairs(int n) {
        if (dp.size() < n)
            for (int i = dp.size(); i < n; ++i) dp.push_back(dp[i - 1] + dp[i - 2]);

        return dp[n - 1];
    }
};

class Solution {
public:
    int rob(vector<int> &nums) {
        vector<int> dp = {0, 0, 0};
        for (auto it = nums.rbegin(); it != nums.rend(); it++)
            dp.push_back(*it + max(dp[dp.size() - 2], dp[dp.size() - 3]));

        return max(dp[dp.size() - 1], dp[dp.size() - 2]);
    }
};

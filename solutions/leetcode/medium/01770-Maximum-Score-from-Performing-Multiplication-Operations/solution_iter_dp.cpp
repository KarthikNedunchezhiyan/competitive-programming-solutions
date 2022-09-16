class Solution {
private:
    int maximumScore(int ni, int mi, vector<int> &nums, vector<int> &multipliers, vector<vector<int>> &dp) {
        if (mi >= multipliers.size()) return 0;

        int nj = nums.size() - 1 - (mi - ni);

        if (dp.size() == mi) dp.emplace_back(mi + 1, INT_MIN);

        if (dp[mi][ni] != INT_MIN) return dp[mi][ni];

        if (ni == nj) return dp[mi][ni] = nums[ni] * multipliers[mi];

        return dp[mi][ni] = max(maximumScore(ni + 1, mi + 1, nums, multipliers, dp) + (nums[ni] * multipliers[mi]),
                                maximumScore(ni, mi + 1, nums, multipliers, dp) + (nums[nj] * multipliers[mi]));
    }

public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers) {
        vector<vector<int>> dp;
        dp.reserve(multipliers.size());
        return maximumScore(0, 0, nums, multipliers, dp);
    }
};

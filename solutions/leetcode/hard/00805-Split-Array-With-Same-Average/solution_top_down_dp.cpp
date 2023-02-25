class Solution {
    bool find(vector<int> &nums, int index, int tsum, int n, vector<vector<vector<bool>>> &dp) {
        if (!n) return !tsum;
        if (index == nums.size()) return false;

        if (!dp[index][n][tsum]) return false;

        bool include = false;
        if ((tsum - nums[index]) >= 0) include = find(nums, index + 1, tsum - nums[index], n - 1, dp);
        return dp[index][n][tsum] = include || find(nums, index + 1, tsum, n, dp);
    }

public:
    bool splitArraySameAverage(vector<int> &nums) {
        const int N = nums.size();
        const int SUM = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 1; i <= nums.size() / 2; ++i) {
            int s1 = SUM * i;
            if (s1 % N != 0) continue;
            s1 /= N;
            vector<vector<vector<bool>>> dp = vector(N, vector(i + 1, vector(s1 + 1, true)));
            if (find(nums, 0, s1, i, dp)) return true;
        }
        return false;
    }
};

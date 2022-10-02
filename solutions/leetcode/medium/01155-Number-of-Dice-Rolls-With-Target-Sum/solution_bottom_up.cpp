class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int> dp = vector(target + 1, 0);
        vector<int> temp = vector(target + 1, 0);

        // base condition
        for (int i = 1; i <= min(k, target); ++i) dp[i] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                temp[j] = 0;
                for (int d = 1; d <= k; ++d) {
                    if ((j - d) < 0) continue;
                    temp[j] = (temp[j] + dp[j - d]) % 1000000007;
                }
            }
            dp = temp;
        }

        return dp[target];
    }
};

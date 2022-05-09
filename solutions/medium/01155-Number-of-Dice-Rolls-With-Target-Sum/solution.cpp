class Solution {
private:
    int k;
    vector<vector<int>> memo;

    int f(int n, int target) {
        if ((n * k) < target || target < 0)
            return 0;

        if ((n * k) == target || (n == 0 && target == 0))
            return 1;

        if (memo[n][target] != -1)
            return memo[n][target];

        int result = 0;

        for (int i = 1; i <= k; i++)
            result = (result + f(n - 1, target - i)) % 1000000007;

        return memo[n][target] = result;
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        this->k = k;
        this->memo = vector(n + 1, vector(target + 1, -1));
        return f(n, target);
    }
};

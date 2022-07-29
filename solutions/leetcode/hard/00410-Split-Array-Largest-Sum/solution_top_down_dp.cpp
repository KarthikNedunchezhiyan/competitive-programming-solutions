class Solution {
private:
    vector<int> prefixSum;
    vector<vector<int>> memo;

    int findSum(int start, int end) {
        return prefixSum[end] - (start == 0 ? 0 : prefixSum[start - 1]);
    }

    int findResult(vector<int> &nums, int start_i, int m) {
        if (start_i >= nums.size() || m > nums.size())
            return INT_MIN;

        // memoization
        if (memo[start_i][m] != -1) return memo[start_i][m];

        if (m == 1) return findSum(start_i, nums.size() - 1);

        if (m == nums.size()) return *max_element(nums.begin() + start_i, nums.end());

        int result = INT_MAX;

        for (int i = start_i; i < nums.size(); i++) {
            int total = findSum(start_i, i);
            result = min(result, max(total, findResult(nums, i + 1, m - 1)));
            if (result < total) break;
        }

        // memoization
        return memo[start_i][m] = result;
    }

public:
    int splitArray(vector<int> &nums, int m) {
        for (int i = 0; i < nums.size(); i++) {
            if (prefixSum.empty()) prefixSum.push_back(nums[i]);
            else prefixSum.push_back(nums[i] + prefixSum[i - 1]);
        }

        memo = vector(nums.size(), vector(m + 1, -1));
        return findResult(nums, 0, m);
    }
};


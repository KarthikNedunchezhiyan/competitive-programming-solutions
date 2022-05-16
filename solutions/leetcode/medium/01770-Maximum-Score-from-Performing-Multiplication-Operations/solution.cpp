class Solution {
private:
    vector<vector<int>> memo;

    int f(int j, int i, vector<int> &nums, vector<int> &multipliers) {
        if (j >= multipliers.size())
            return 0;

        int l = nums.size() - 1 - (j - i);

        if (i == l)
            return nums[i] * multipliers[j];

        if (memo[j][i] != 0) {
            return memo[j][i];
        }

        memo[j][i] = max((nums[i] * multipliers[j]) + f(j + 1, i + 1, nums, multipliers),
                         (nums[l] * multipliers[j]) + f(j + 1, i, nums, multipliers));

        return memo[j][i];
    }

public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers) {
        memo = vector(multipliers.size() + 1, vector(multipliers.size() + 1, 0));
        return f(0, 0, nums, multipliers);
    }
};

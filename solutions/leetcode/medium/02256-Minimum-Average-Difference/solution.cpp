class Solution {
    long safeDiv(long nu, long de) {
        if (!de) return 0;
        return nu / de;
    }

    long accumulate(vector<int> &nums) {
        long result = 0;
        for (int &num: nums) result += num;
        return result;
    }

public:
    int minimumAverageDifference(vector<int> &nums) {
        long suffix_sum = accumulate(nums), prefix_sum = 0;
        long result = -1, min_avg_diff = INT_MAX, len = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];
            suffix_sum -= nums[i];
            long curr_avg_diff = abs(safeDiv(prefix_sum, i + 1) - safeDiv(suffix_sum, len - i - 1));
            if (curr_avg_diff < min_avg_diff) {
                min_avg_diff = curr_avg_diff;
                result = i;
            }
        }

        return result;
    }
};

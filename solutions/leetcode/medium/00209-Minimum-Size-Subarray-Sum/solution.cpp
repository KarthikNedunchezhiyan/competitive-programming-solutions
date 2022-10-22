class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int start = 0, result = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            target -= nums[i];
            while (target <= 0) {
                result = min(result, i - start + 1);
                target += nums[start++];
            }
        }

        return result == INT_MAX ? 0 : result;
    }
};

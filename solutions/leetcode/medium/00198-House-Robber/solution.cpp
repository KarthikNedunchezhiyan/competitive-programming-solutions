class Solution {
public:
    int rob(vector<int> &nums) {
        int nums_len = nums.size();

        if (nums_len <= 2) {
            return (nums_len == 1) ? nums[0] : max(nums[0], nums[1]);
        }

        int prevminone = nums[0], prev = max(nums[0], nums[1]), curr;

        for (int i = 2; i < nums_len; i++) {
            curr = max(prev, prevminone + nums[i]);
            prevminone = prev;
            prev = curr;
        }

        return prev;
    }
};

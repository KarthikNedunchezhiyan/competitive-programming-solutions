class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        // Finding the max subarray using kadane's algorithm
        int sum = nums[0];
        int max_subarray = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            if (sum < nums[i])
                sum = nums[i];

            max_subarray = max(max_subarray, sum);
        }

        // Finding second case (max subarray split into first and second half due to circular nature)
        vector<int> memo1 = vector(nums.size(), 0);
        sum = 0;
        int current_max = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            sum += nums[i];
            current_max = max(current_max, sum);
            memo1[i] = current_max;
        }

        vector<int> memo2 = vector(nums.size(), 0);
        sum = 0;
        current_max = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            current_max = max(current_max, sum);
            memo2[i] = current_max;
        }


        for (int i = 1; i < nums.size(); i++) {
            int max_sum = memo1[i] + memo2[i - 1];
            max_subarray = max(max_subarray, max_sum);
        }

        return max_subarray;
    }
};

class Solution {
private:
    vector<int> nums;
    vector<int> memo;

    int f(int start_index) {
        if (start_index >= nums.size())
            return 0;

        if (memo[start_index] != -1)
            return memo[start_index];

        int result = 1;

        for (int i = start_index + 1; i < nums.size(); i++)
            if (nums[i] > nums[start_index])
                result = max(result, 1 + f(i));

        return memo[start_index] = result;
    }

public:
    int lengthOfLIS(vector<int> &nums) {
        this->nums = nums;
        this->memo = vector(nums.size(), -1);
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
            result = max(result, f(i));
        
	return result;
    }
};

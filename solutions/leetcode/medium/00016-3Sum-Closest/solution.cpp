class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, result = INT_MAX;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];

                if (abs(target - sum) < diff) {
                    diff = abs(sum - target);
                    result = sum;
                }
                
                if (sum > target) --end;
                else if (sum < target) ++start;
                else return sum;
            }
        }

        return result;
    }
};

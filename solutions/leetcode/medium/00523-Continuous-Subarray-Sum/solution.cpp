class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> reminder_lookup = {{0, -1}};
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int reminder = (sum += nums[i]) % k;
            if (reminder_lookup.count(reminder))
                if ((i - reminder_lookup[reminder]) > 1) return true;
                else continue;
            reminder_lookup[reminder] = i;
        }
        return false;
    }
};

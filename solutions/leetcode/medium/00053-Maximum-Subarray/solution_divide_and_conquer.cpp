class Solution {
private:
    int f(int s, int e, vector<int> &nums) {
        if (s == e) return nums[s];

        int mid = s + (e - s) / 2;

        int bridged_value = INT_MIN, temp = 0;

        for (int i = mid; i >= s; --i)
            bridged_value = max(temp += nums[i], bridged_value);

        temp = bridged_value;

        for (int i = mid + 1; i <= e; ++i)
            bridged_value = max(temp += nums[i], bridged_value);

        return max(f(s, mid, nums), max(f(mid + 1, e, nums), bridged_value));
    }

public:
    int maxSubArray(vector<int> &nums) {
        return f(0, nums.size() - 1, nums);
    }
};

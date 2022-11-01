class Solution {
public:
    int missingElement(vector<int> &nums, int k) {
        int start = 0, end = nums.size() - 1;
        while ((end - start) > 1) {
            int mid = start + (end - start) / 2;
            int missing = (nums[mid] - nums[start]) - (mid - start);
            if (missing >= k) end = mid - 1;
            else {
                start = mid;
                k -= missing;
            }
        }

        if (start == end) return nums[start] + k;
        int missing = nums[start] + k;
        return nums[end] <= missing ? missing + 1 : missing;
    }
};

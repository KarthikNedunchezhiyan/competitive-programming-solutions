class Solution {
public:
    int missingElement(vector<int> &nums, int k) {
        int s = 0, e = nums.size() - 1;

        while (s + 1 < e) {
            int mid = s + (e - s) / 2;
            int left_missing = nums[mid] - nums[s] - mid + s;

            if (left_missing >= k) e = mid - 1;
            else {
                s = mid;
                k -= left_missing;
            }
        }

        int result = nums[s] + k;
        return (s != e && result >= nums[e]) ? result + 1 : result;
    }
};

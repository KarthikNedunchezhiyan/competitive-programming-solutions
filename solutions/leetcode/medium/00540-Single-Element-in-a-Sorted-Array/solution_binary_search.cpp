class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;

        while ((left + 1) < right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid - 1] == nums[mid] && mid % 2) left = mid + 1;
            else if (nums[mid - 1] != nums[mid] && !(mid % 2)) left = mid;
            else right = mid;
        }
        return (right % 2) ? nums[left] : nums[right];
    }
};

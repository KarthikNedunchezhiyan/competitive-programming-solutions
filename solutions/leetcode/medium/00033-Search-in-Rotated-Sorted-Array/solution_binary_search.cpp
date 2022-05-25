class Solution {
private:
    vector<int> nums;
    int target;

    int f(int left, int right) {
        if (left > right)
            return -1;

        int middle = left + (right - left) / 2;

        if (nums[middle] == target) return middle;

        if (nums[middle] < nums[right])
            return (target > nums[middle] && target <= nums[right]) ? f(middle + 1, right) : f(left, middle - 1);

        return (target <= nums[right] || target > nums[middle]) ? f(middle + 1, right) : f(left, middle - 1);
    }

public:
    int search(vector<int> &nums, int target) {
        this->nums = nums;
        this->target = target;
        return f(0, nums.size() - 1);
    }
};

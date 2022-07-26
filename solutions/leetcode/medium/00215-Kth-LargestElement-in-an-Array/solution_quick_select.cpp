class Solution {
private:
    vector<int> nums;
    int targetIndex;

    int partition(int start, int end) {
        int cursor = start;

        for (int i = start; i < end; i++)
            if (nums[i] <= nums[end])
                iter_swap(nums.begin() + cursor++, nums.begin() + i);

        iter_swap(nums.begin() + cursor, nums.begin() + end);
        return cursor;
    }

    int quickSelect(int start, int end) {
        int pivotIndex = partition(start, end);
        if (pivotIndex == targetIndex)
            return nums[targetIndex];

        return pivotIndex > targetIndex ? quickSelect(start, pivotIndex - 1) : quickSelect(pivotIndex + 1, end);
    }

public:
    int findKthLargest(vector<int> &nums, int k) {
        this->nums = nums;
        this->targetIndex = nums.size() - k;
        return quickSelect(0, nums.size() - 1);
    }
};

class Solution {
private:
    vector<int> nums;

    int search(int left, int right) {
        if (left == right) return left;

        int middle = (left + right) / 2;

        return nums[middle] > nums[middle + 1] ? search(left, middle) : search(middle + 1, right);
    }

public:
    int findPeakElement(vector<int> &nums) {
        this->nums = nums;
        return search(0, nums.size() - 1);
    }
};

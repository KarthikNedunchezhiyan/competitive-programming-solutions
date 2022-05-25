class Solution {
private:
    vector<int> nums;
    int target;

    int search(int l, int r, bool lookingStart) {
        if (l > r)
            return -1;

        if (l + 1 == r || l == r) {
            if (nums[l] == target && nums[r] == target)
                return lookingStart ? l : r;
            return nums[l] == target ? l : nums[r] == target ? r : -1;
        }

        int mid = (l + r) / 2;

        if (nums[mid] == target)
            return search(lookingStart ? l : mid, lookingStart ? mid : r, lookingStart);

        return nums[mid] > target ? search(l, mid - 1, lookingStart) : search(mid + 1, r, lookingStart);
    }

public:
    vector<int> searchRange(vector<int> &nums, int target) {
        this->nums = nums;
        this->target = target;

        return {search(0, nums.size() - 1, true), search(0, nums.size() - 1, false)};
    }
};

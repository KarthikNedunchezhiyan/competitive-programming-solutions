class Solution {
private:
    vector<int> nums;

    int search(int l, int r) {
        if (l == r || l + 1 == r)
            return min(nums[l], nums[r]);

        int mid = (l + r) / 2;

        if (min(nums[l], nums[r]) < nums[mid])
            return nums[l] < nums[r] ? search(l, mid - 1) : search(mid + 1, r);

        return nums[l] > nums[r] ? search(l, mid) : search(mid, r);
    }

public:
    int findMin(vector<int> &nums) {
        this->nums = nums;
        return search(0, nums.size() - 1);
    }
};

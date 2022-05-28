class Solution {
private:
    vector<int> nums;

    int search(int l, int r) {
        if (l == r || l + 1 == r)
            return min(nums[l], nums[r]);

        int mid = l + (r - l) / 2;

        if (nums[mid] > nums[l] || nums[mid] > nums[r])
            return nums[l] < nums[r] ? search(l, mid) : search(mid, r);

        if (nums[mid - 1] != nums[mid + 1])
            return nums[mid - 1] < nums[mid + 1] ? search(l, mid) : search(mid, r);

        return min(search(l + 1, mid), search(mid, r - 1));
    }

public:
    int findMin(vector<int> &nums) {
        this->nums = nums;
        return search(0, nums.size() - 1);
    }
};

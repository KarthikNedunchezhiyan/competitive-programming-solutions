class Solution {
    void sort(vector<int> &nums, int start, int end) {
        if (start == end) return;

        int mid = start + (end - start) / 2;
        sort(nums, start, mid);
        sort(nums, mid + 1, end);

        int i = start, j = mid + 1;
        vector<int> temp;

        while (i <= mid && j <= end) {
            if (nums[i] < nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= end) temp.push_back(nums[j++]);

        copy(temp.begin(), temp.end(), nums.begin() + start);
    }

public:
    vector<int> sortArray(vector<int> &nums) {
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
};

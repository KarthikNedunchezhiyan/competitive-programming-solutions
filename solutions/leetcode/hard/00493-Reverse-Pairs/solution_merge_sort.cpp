class Solution {
private:
    void merge(vector<int> &nums, int s, int mid, int e) {
        const int t_size = e - s + 1;
        int temp[t_size];
        int i = s, j = mid + 1, ti = 0;
        while (i <= mid && j <= e)
            temp[ti++] = nums[i] < nums[j] ? nums[i++] : nums[j++];

        while (i <= mid) temp[ti++] = nums[i++];
        while (j <= e) temp[ti++] = nums[j++];

        copy(temp, temp + t_size, nums.begin() + s);
    }

    int countRevPairs(vector<int> &nums, int s, int mid, int e) {
        int i = s, j = mid + 1, count = 0;

        while (i <= mid) {
            while (j <= e) {
                if ((long) nums[i] <= 2 * (long) nums[j]) break;
                ++j;
            }
            count += j - (mid + 1);
            ++i;
        }

        return count;
    }

    int mergeSort(vector<int> &nums, int s, int e) {
        if (s >= e) return 0;

        int mid = s + ((e - s) / 2);
        int count = mergeSort(nums, s, mid) + mergeSort(nums, mid + 1, e) + countRevPairs(nums, s, mid, e);

        // we don't actually need to perform the merge for top recursion layer. Just an optimization.
        if (!(s == 0 && e == nums.size() - 1))
            merge(nums, s, mid, e);

        return count;
    }

public:
    int reversePairs(vector<int> &nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

class Solution {
private:
    int countLessThanOrEqual(int x, vector<int> &nums) {
        int res = 0;
        for (int &num: nums) if (num <= x) ++res;
        return res;
    }

    int search(int start, int end, vector<int> &nums) {
        if (start == end) return start;

        int mid = start + (end - start) / 2;

        if (countLessThanOrEqual(mid, nums) <= mid) return search(mid + 1, end, nums);
        return search(start, mid, nums);
    }

public:
    int findDuplicate(vector<int> &nums) {
        return search(1, nums.size() - 1, nums);
    }
};

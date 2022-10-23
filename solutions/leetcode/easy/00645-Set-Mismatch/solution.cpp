class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        int duplicate = 0, sum = 0;
        for (int &n: nums) {
            int abs_n = abs(n);
            sum += abs_n;
            if (nums[abs_n - 1] > 0)
                nums[abs_n - 1] *= -1;
            else duplicate = abs_n;
        }
        int expected = ((nums.size() + 1) * nums.size()) / 2;
        return {duplicate, expected - (sum - duplicate)};
    }
};

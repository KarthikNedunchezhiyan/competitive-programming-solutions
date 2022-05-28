class Solution {
public:
    int missingNumber(vector<int> &nums) {
        return -1 * accumulate(nums.begin(), nums.end(), -1 * ((nums.size() * (nums.size() + 1)) >> 1));
    }
};

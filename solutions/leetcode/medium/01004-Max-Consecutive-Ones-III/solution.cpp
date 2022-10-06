class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int flipped = 0, start = 0, i = 0, result = 0;

        while (i < nums.size()) {
            if (!nums[i] && flipped < k) ++flipped;
            else if (!nums[i]) {
                while (nums[start++] != 0);
                    --flipped;
                    continue;
            }

            result = max(result, i++ - start + 1);
        }

        return result;
    }
};

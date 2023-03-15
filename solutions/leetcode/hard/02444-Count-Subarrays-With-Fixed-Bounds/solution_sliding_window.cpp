class Solution {
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        long long result = 0, left = 0, minIndex = -1, maxIndex = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                minIndex = maxIndex = -1;
                left = i + 1;
                continue;
            }

            if (nums[i] == minK) minIndex = i;
            if (nums[i] == maxK) maxIndex = i;

            if (minIndex != -1 && maxIndex != -1)
                result += min(minIndex, maxIndex) - left + 1;
        }

        return result;
    }
};

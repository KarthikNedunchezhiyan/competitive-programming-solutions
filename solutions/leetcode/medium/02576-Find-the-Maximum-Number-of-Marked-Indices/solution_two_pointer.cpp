class Solution {
public:
    int maxNumOfMarkedIndices(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        int maxMarked = 0, N = nums.size(), i = 0, mid = N / 2, j = mid;

        while (i < mid && j < N) {
            if (nums[i] * 2 <= nums[j]) {
                maxMarked += 2;
                i++;
            }
            j++;
        }
        
        return maxMarked;
    }
};

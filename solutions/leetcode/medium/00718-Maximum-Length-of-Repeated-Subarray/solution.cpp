class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int dp[nums1.size()][nums2.size()];
        int result = 0;
        for (int i = 0; i < nums1.size(); ++i)
            for (int j = 0; j < nums2.size(); ++j)
                result = max(result,
                             dp[i][j] = nums1[i] != nums2[j] ? 0 : i && j ? dp[i - 1][j - 1] + 1 : 1);

        return result;
    }
};

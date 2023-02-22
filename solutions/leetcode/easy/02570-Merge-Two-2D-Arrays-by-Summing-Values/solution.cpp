class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2) {
        vector<vector<int>> result;
        int c1 = 0, c2 = 0;
        while (c1 < nums1.size() && c2 < nums2.size()) {
            if (nums1[c1][0] < nums2[c2][0]) result.push_back(nums1[c1++]);
            else if (nums2[c2][0] < nums1[c1][0]) result.push_back(nums2[c2++]);
            else result.push_back({nums1[c1][0], nums1[c1++][1] + nums2[c2++][1]});
        }

        while (c1 < nums1.size()) result.push_back(nums1[c1++]);
        while (c2 < nums2.size()) result.push_back(nums2[c2++]);

        return result;
    }
};

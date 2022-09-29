class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> temp;
        temp.reserve(nums1.size());

        int num1_i = 0, num2_i = 0;

        while (num1_i < m && num2_i < n)
            temp.emplace_back(nums1[num1_i] < nums2[num2_i] ? nums1[num1_i++] : nums2[num2_i++]);

        while (num1_i < m) temp.emplace_back(nums1[num1_i++]);
        while (num2_i < n) temp.emplace_back(nums2[num2_i++]);

        copy(temp.begin(), temp.end(), nums1.begin());
    }
};

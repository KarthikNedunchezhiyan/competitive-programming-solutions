class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        int frequency[1001];
        memset(frequency, 0, sizeof(frequency));

        for (int &num: nums1) ++frequency[num];

        vector<int> result;

        for (int &num: nums2)
            if (frequency[num]) {
                --frequency[num];
                result.emplace_back(num);
            }

        return result;
    }
};class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        int frequency[1001];
        memset(frequency, 0, sizeof(frequency));

        for (int &num: nums1) ++frequency[num];

        vector<int> result;

        for (int &num: nums2)
            if (frequency[num]) {
                --frequency[num];
                result.emplace_back(num);
            }

        return result;
    }
};

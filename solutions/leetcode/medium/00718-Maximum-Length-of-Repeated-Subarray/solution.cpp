class Solution {
private:
    int r, c;
    vector<vector<int>> memo;

    int get_value(int i, int j) {
        return (i < 0 || j < 0 || i >= r || j >= c) ? 0 : memo[i][j];
    }

public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        this->r = nums1.size();
        this->c = nums2.size();
        this->memo = vector(nums1.size(), vector(nums2.size(), 0));

        int result = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                if (nums1[i] == nums2[j])
                    memo[i][j] = get_value(i - 1, j - 1) + 1;

                result = max(result, memo[i][j]);
            }

        return result;
    }
};

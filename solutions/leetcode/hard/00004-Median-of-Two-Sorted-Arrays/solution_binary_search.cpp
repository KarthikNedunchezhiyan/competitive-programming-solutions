class Solution {
    int get(vector<int> &t, int index) {
        return index < 0 ? INT_MIN : index >= t.size() ? INT_MAX : t[index];
    }

    double bS(int start, int end, vector<int> &t1, vector<int> &t2) {
        while (true) {
            int actual_left_count = (t1.size() + t2.size() + 1) / 2;
            int t1_lft = end < 0 ? -1 : start + (end - start) / 2;
            int t2_lft = actual_left_count - t1_lft - 2;

            if (!(end < 0 || t2_lft >= t2.size() || start >= t1.size() || t2_lft < 0)) {
                if (get(t1, t1_lft + 1) < t2[t2_lft]) {
                    start = t1_lft + 1;
                    continue;
                } else if (get(t2, t2_lft + 1) < t1[t1_lft]) {
                    end = t1_lft - 1;
                    continue;
                }
            }

            int x = max(get(t1, t1_lft), get(t2, t2_lft));
            if ((t1.size() + t2.size()) % 2) return x;

            return ((double) (x + min(get(t1, t1_lft + 1), get(t2, t2_lft + 1)))) / 2;
        }
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        return nums1.size() < nums2.size() ?
               bS(0, nums1.size() - 1, nums1, nums2) :
               bS(0, nums2.size() - 1, nums2, nums1);
    }
};

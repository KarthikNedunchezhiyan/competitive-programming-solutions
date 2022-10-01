class Solution {
private:
    int cutCount(int max_sweet, vector<int> &sweetness) {
        int current_sweet = 0, cut_count = 0;

        for (int &sweet: sweetness) {
            current_sweet += sweet;
            if (current_sweet >= max_sweet) {
                current_sweet = 0;
                ++cut_count;
            }
        }

        return cut_count;
    }

public:
    int maximizeSweetness(vector<int> &sweetness, int k) {
        int s = 1, e = INT_MAX, split = k + 1;

        while (s <= e) {
            if ((e - s) <= 1) return cutCount(e, sweetness) == split ? e : s;

            int mid = s + (e - s) / 2;

            if (cutCount(mid, sweetness) < split) e = mid - 1;
            else s = mid;
        }

        return -1;
    }
};

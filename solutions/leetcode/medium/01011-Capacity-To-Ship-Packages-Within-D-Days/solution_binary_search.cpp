class Solution {
    int getDirection(vector<int> &weights, int days, int limit) {
        int _days = 1, sum = 0;
        for (int weight: weights) {
            if ((sum + weight) > limit) {
                ++_days;
                sum = 0;
            }
            sum += weight;
        }
        return days >= _days ? -1 : 1;
    }

public:
    int shipWithinDays(vector<int> &weights, int days) {
        int left = 0, right = 0;
        for (int weight: weights) {
            right += weight;
            left = max(weight, left);
        }
        if (days == 1) return right;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (getDirection(weights, days, mid) == -1) right = mid;
            else left = mid + 1;
        }

        return left;
    }
};

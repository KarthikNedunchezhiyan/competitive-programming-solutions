class Solution {
public:
    long long minimumTime(vector<int> &time, int totalTrips) {
        long long left = 0, right = LLONG_MAX;

        while (left < right) {
            long long mid = left + (right - left) / 2;

            long long tripsMade = 0;
            for (int &t: time) {
                tripsMade += mid / t;
                if (tripsMade > totalTrips) break;
            }

            if (tripsMade >= totalTrips) right = mid;
            else left = mid + 1;
        }

        return left;
    }
};

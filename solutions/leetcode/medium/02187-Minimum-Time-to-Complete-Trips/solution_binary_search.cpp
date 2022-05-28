class Solution {
    vector<int> times;

    long long totalTripsAtInstance(long long instance) {
        long long totalTrips = 0;
        for (long long time: times)
            totalTrips += instance / time;

        return totalTrips;
    }

public:
    long long minimumTime(vector<int> &time, long long totalTrips) {
        times = time;
        long long l = 1, r = times[0] * totalTrips;

        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (totalTripsAtInstance(mid) >= totalTrips) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};

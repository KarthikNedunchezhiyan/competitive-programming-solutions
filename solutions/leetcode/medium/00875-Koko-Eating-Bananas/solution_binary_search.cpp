class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int min = 1, max = INT_MAX;

        while (min < max) {
            int mid = min + (max - min) / 2;

            int time = 0;
            for (int pile: piles) {
                time += pile / mid;
                if (pile % mid) ++time;
            }
            
            if (time <= h) max = mid;
            else min = mid + 1;
        }
        return max;
    }
};
